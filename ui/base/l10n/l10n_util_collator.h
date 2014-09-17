// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_BASE_L10N_L10N_UTIL_COLLATOR_H_
#define UI_BASE_L10N_L10N_UTIL_COLLATOR_H_

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include "base/i18n/string_compare.h"
#include "base/memory/scoped_ptr.h"
#include "ui/base/ui_base_export.h"

#if !defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
#include "third_party/icu/source/i18n/unicode/coll.h"
#endif

namespace l10n_util {

// Used by SortStringsUsingMethod. Invokes a method on the objects passed to
// operator (), comparing the string results using a collator.
template <class T, class Method>
class StringMethodComparatorWithCollator
    : public std::binary_function<const base::string16&,
                                  const base::string16&,
                                  bool> {
 public:
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  StringMethodComparatorWithCollator(const std::string&locale, Method method)
      : locale_(locale),
#else
  StringMethodComparatorWithCollator(icu::Collator* collator, Method method)
      : collator_(collator),
#endif
        method_(method) { }

  // Returns true if lhs preceeds rhs.
  bool operator() (T* lhs_t, T* rhs_t) {
    return base::i18n::CompareString16WithCollator(
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
        locale_,
#else
        *collator_,
#endif
        (lhs_t->*method_)(), (rhs_t->*method_)()) == UCOL_LESS;
  }

 private:
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  std::string locale_;
#else
  icu::Collator* collator_;
#endif
  Method method_;
};

// Used by SortStringsUsingMethod. Invokes a method on the objects passed to
// operator (), comparing the string results using <.
template <class T, class Method>
class StringMethodComparator
    : public std::binary_function<const base::string16&,
                                  const base::string16&,
                                  bool> {
 public:
  explicit StringMethodComparator(Method method) : method_(method) { }

  // Returns true if lhs preceeds rhs.
  bool operator() (T* lhs_t, T* rhs_t) {
    return (lhs_t->*method_)() < (rhs_t->*method_)();
  }

 private:
  Method method_;
};

// Sorts the objects in |elements| using the method |method|, which must return
// a string. Sorting is done using a collator, unless a collator can not be
// found in which case the strings are sorted using the operator <.
template <class T, class Method>
void SortStringsUsingMethod(const std::string& locale,
                            std::vector<T*>* elements,
                            Method method) {
#if !defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  UErrorCode error = U_ZERO_ERROR;
  icu::Locale loc(locale.c_str());
  scoped_ptr<icu::Collator> collator(icu::Collator::createInstance(loc, error));
  if (U_FAILURE(error)) {
    sort(elements->begin(), elements->end(),
         StringMethodComparator<T, Method>(method));
    return;
  }
#endif

  std::sort(elements->begin(), elements->end(),
      StringMethodComparatorWithCollator<T, Method>(
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
          locale,
#else
          collator.get(),
#endif
          method));
}

// Compares two elements' string keys and returns true if the first element's
// string key is less than the second element's string key. The Element must
// have a method like the follow format to return the string key.
// const base::string16& GetStringKey() const;
// This uses the locale specified in the constructor.
template <class Element>
class StringComparator : public std::binary_function<const Element&,
                                                     const Element&,
                                                     bool> {
 public:
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  StringComparator(const std::string& locale)
      : locale_(locale) { }
#else
  explicit StringComparator(icu::Collator* collator)
      : collator_(collator) { }
#endif

  // Returns true if lhs precedes rhs.
  bool operator()(const Element& lhs, const Element& rhs) {
    const base::string16& lhs_string_key = lhs.GetStringKey();
    const base::string16& rhs_string_key = rhs.GetStringKey();

#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
    return StringComparator<base::string16>(locale_)(
#else
    return StringComparator<base::string16>(collator_)(
#endif
        lhs_string_key, rhs_string_key);
  }

 private:
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  std::string locale_;
#else
  icu::Collator* collator_;
#endif
};

// Specialization of operator() method for base::string16 version.
template <>
UI_BASE_EXPORT inline bool StringComparator<base::string16>::operator()(
    const base::string16& lhs,
    const base::string16& rhs) {
  // If we can not get collator instance for specified locale, just do simple
  // string compare.
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  return base::i18n::CompareString16WithCollator(locale_, lhs, rhs) ==
      UCOL_LESS;
#else
  if (!collator_)
    return lhs < rhs;
  return base::i18n::CompareString16WithCollator(*collator_, lhs, rhs) ==
         UCOL_LESS;
#endif
}

// In place sorting of |elements| of a vector according to the string key of
// each element in the vector by using collation rules for |locale|.
// |begin_index| points to the start position of elements in the vector which
// want to be sorted. |end_index| points to the end position of elements in the
// vector which want to be sorted.
template <class Element>
void SortVectorWithStringKey(const std::string& locale,
                             std::vector<Element>* elements,
                             size_t begin_index,
                             size_t end_index,
                             bool needs_stable_sort) {
  DCHECK_LT(begin_index, end_index);
  DCHECK_LE(end_index, elements->size());
#if defined(USE_ICU_ALTERNATIVES_ON_ANDROID)
  StringComparator<Element> c(locale);
#else
  UErrorCode error = U_ZERO_ERROR;
  icu::Locale loc(locale.c_str());
  scoped_ptr<icu::Collator> collator(icu::Collator::createInstance(loc, error));
  if (U_FAILURE(error))
    collator.reset();
  StringComparator<Element> c(collator.get());
#endif
  if (needs_stable_sort) {
    stable_sort(elements->begin() + begin_index,
                elements->begin() + end_index,
                c);
  } else {
    sort(elements->begin() + begin_index, elements->begin() + end_index, c);
  }
}

template <class Element>
void SortVectorWithStringKey(const std::string& locale,
                             std::vector<Element>* elements,
                             bool needs_stable_sort) {
  SortVectorWithStringKey<Element>(locale, elements, 0, elements->size(),
                                   needs_stable_sort);
}

}  // namespace l10n_util

#endif  // UI_BASE_L10N_L10N_UTIL_COLLATOR_H_
