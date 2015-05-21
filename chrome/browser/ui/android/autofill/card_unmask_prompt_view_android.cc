// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/android/autofill/card_unmask_prompt_view_android.h"

#include "chrome/browser/android/resource_mapper.h"
#include "chrome/browser/ui/autofill/create_card_unmask_prompt_view.h"
#include "components/autofill/core/browser/ui/card_unmask_prompt_controller.h"
#include "content/public/browser/web_contents.h"
#include "jni/CardUnmaskBridge_jni.h"
#include "ui/android/view_android.h"
#include "ui/android/window_android.h"

namespace autofill {

CardUnmaskPromptView* CreateCardUnmaskPromptView(
    CardUnmaskPromptController* controller,
    content::WebContents* web_contents) {
  return new CardUnmaskPromptViewAndroid(controller, web_contents);
}

CardUnmaskPromptViewAndroid::CardUnmaskPromptViewAndroid(
    CardUnmaskPromptController* controller,
    content::WebContents* web_contents)
    : controller_(controller), web_contents_(web_contents) {
}

CardUnmaskPromptViewAndroid::~CardUnmaskPromptViewAndroid() {
  if (controller_)
    controller_->OnUnmaskDialogClosed();
}

void CardUnmaskPromptViewAndroid::Show() {
  JNIEnv* env = base::android::AttachCurrentThread();
  ui::ViewAndroid* view_android = web_contents_->GetNativeView();

  ScopedJavaLocalRef<jstring> dialog_title =
      base::android::ConvertUTF16ToJavaString(env,
                                              controller_->GetWindowTitle());
  ScopedJavaLocalRef<jstring> instructions =
      base::android::ConvertUTF16ToJavaString(
          env, controller_->GetInstructionsMessage());
  java_object_.Reset(Java_CardUnmaskBridge_create(
      env, reinterpret_cast<intptr_t>(this), dialog_title.obj(),
      instructions.obj(),
      ResourceMapper::MapFromChromiumId(controller_->GetCvcImageRid()),
      controller_->ShouldRequestExpirationDate(),
      controller_->CanStoreLocally(),
      controller_->GetStoreLocallyStartState(),
      view_android->GetWindowAndroid()->GetJavaObject().obj()));

  Java_CardUnmaskBridge_show(env, java_object_.obj());
}

bool CardUnmaskPromptViewAndroid::CheckUserInputValidity(JNIEnv* env,
                                                         jobject obj,
                                                         jstring response) {
  return controller_->InputCvcIsValid(
      base::android::ConvertJavaStringToUTF16(env, response));
}

void CardUnmaskPromptViewAndroid::OnUserInput(JNIEnv* env,
                                              jobject obj,
                                              jstring cvc,
                                              jstring month,
                                              jstring year,
                                              jboolean should_store_locally) {
  controller_->OnUnmaskResponse(
      base::android::ConvertJavaStringToUTF16(env, cvc),
      base::android::ConvertJavaStringToUTF16(env, month),
      base::android::ConvertJavaStringToUTF16(env, year),
      should_store_locally);
}

void CardUnmaskPromptViewAndroid::OnNewCardLinkClicked(JNIEnv* env,
                                                       jobject obj) {
  controller_->NewCardLinkClicked();
  Java_CardUnmaskBridge_update(env, java_object_.obj(),
      base::android::ConvertUTF16ToJavaString(
          env, controller_->GetWindowTitle()).obj(),
      base::android::ConvertUTF16ToJavaString(
          env, controller_->GetInstructionsMessage()).obj(),
      controller_->ShouldRequestExpirationDate());
}

void CardUnmaskPromptViewAndroid::PromptDismissed(JNIEnv* env, jobject obj) {
  delete this;
}

void CardUnmaskPromptViewAndroid::ControllerGone() {
  controller_ = nullptr;
  JNIEnv* env = base::android::AttachCurrentThread();
  Java_CardUnmaskBridge_dismiss(env, java_object_.obj());
}

void CardUnmaskPromptViewAndroid::DisableAndWaitForVerification() {
  JNIEnv* env = base::android::AttachCurrentThread();
  Java_CardUnmaskBridge_disableAndWaitForVerification(env, java_object_.obj());
}

void CardUnmaskPromptViewAndroid::GotVerificationResult(
    const base::string16& error_message,
    bool allow_retry) {
  JNIEnv* env = base::android::AttachCurrentThread();
  ScopedJavaLocalRef<jstring> message;
  if (!error_message.empty())
      message = base::android::ConvertUTF16ToJavaString(env, error_message);

  Java_CardUnmaskBridge_verificationFinished(env, java_object_.obj(),
                                             message.obj(), allow_retry);
}

// static
bool CardUnmaskPromptViewAndroid::Register(JNIEnv* env) {
  return RegisterNativesImpl(env);
}

}  // namespace autofill
