// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.chromium.ui.base;

import android.content.res.Configuration;
import android.view.View;

import org.chromium.base.ApiCompatibilityUtils;
import org.chromium.base.ApplicationStatus;
import org.chromium.base.CalledByNative;
import org.chromium.base.JNINamespace;
import org.chromium.base.LocaleUtils;

import java.util.Locale;
import java.util.concurrent.TimeUnit;

/**
 * This class provides the locale related methods for the native library.
 */
@JNINamespace("l10n_util")
public class LocalizationUtils {

    // This is mirrored from base/i18n/rtl.h. Please keep in sync.
    public static final int UNKNOWN_DIRECTION = 0;
    public static final int RIGHT_TO_LEFT = 1;
    public static final int LEFT_TO_RIGHT = 2;

    private static Boolean sIsLayoutRtl;

    private LocalizationUtils() { /* cannot be instantiated */ }

    /**
     * @return the default locale, translating Android deprecated
     * language codes into the modern ones used by Chromium.
     */
    @CalledByNative
    public static String getDefaultLocale() {
        // TODO(vivekg): Native callers should use LocaleUtils directly instead of the redirection.
        return LocaleUtils.getDefaultLocale();
    }

    private static Locale getJavaLocale(String language, String country, String variant) {
        return new Locale(language, country, variant);
    }

    @CalledByNative
    private static String getDisplayNameForLocale(Locale locale, Locale displayLocale) {
        return locale.getDisplayName(displayLocale);
    }

    /**
     * Returns whether the Android layout direction is RTL.
     *
     * Note that the locale direction can be different from layout direction. Two known cases:
     * - RTL languages on Android 4.1, due to the lack of RTL layout support on 4.1.
     * - When user turned on force RTL layout option under developer options.
     *
     * Therefore, only this function should be used to query RTL for layout purposes.
     */
    @CalledByNative
    public static boolean isLayoutRtl() {
        if (sIsLayoutRtl == null) {
            Configuration configuration =
                    ApplicationStatus.getApplicationContext().getResources().getConfiguration();
            sIsLayoutRtl = Boolean.valueOf(
                    ApiCompatibilityUtils.getLayoutDirection(configuration) ==
                    View.LAYOUT_DIRECTION_RTL);
        }

        return sIsLayoutRtl.booleanValue();
    }

    /**
     * Jni binding to base::i18n::GetFirstStrongCharacterDirection
     * @param string String to decide the direction.
     * @return One of the UNKNOWN_DIRECTION, RIGHT_TO_LEFT, and LEFT_TO_RIGHT.
     */
    public static int getFirstStrongCharacterDirection(String string) {
        return nativeGetFirstStrongCharacterDirection(string);
    }

    /**
     * Jni binding to ui::TimeFormat::TimeRemaining. Converts milliseconds to
     * time remaining format : "3 mins left", "2 days left".
     * @param timeInMillis time in milliseconds
     * @return time remaining
     */
    public static String getDurationString(long timeInMillis) {
        String ret = nativeGetDurationString(timeInMillis);
        if (ret != null) {
            return ret;
        } else {
            // Probably defined USE_ICU_ALTERNATIVES_ON_ANDROID
            int type = 0;  //Days
            long count = 0;
            while (true) {
                switch (type) {
                    case 0:  // Days
                        count = TimeUnit.MILLISECONDS.toDays(timeInMillis);
                        break;
                    case 1:  // Hours
                        count = TimeUnit.MILLISECONDS.toHours(timeInMillis);
                        break;
                    case 2:  // Mins
                        count = TimeUnit.MILLISECONDS.toMinutes(timeInMillis);
                        break;
                    case 3:  // Secs
                        count = TimeUnit.MILLISECONDS.toSeconds(timeInMillis);
                        break;
                    default:
                        return "0 sec left";
                }
                if (count > 0) break;
                type++;
            }
            String unit;
            switch (type) {
                case 0:  // Days
                    unit = "day";
                    break;
                case 1:  // Hours
                    unit = "hour";
                    break;
                case 2:  // Mins
                    unit = "min";
                    break;
                case 3:  // Secs
                    unit = "sec";
                    break;
                default:
                    return "0 sec left";
            }
            String plural = "";
            if (count > 1) plural = "s";
            return String.format("%d %s%s left", count, unit, plural);
        }
    }

    private static native int nativeGetFirstStrongCharacterDirection(String string);

    private static native String nativeGetDurationString(long timeInMillis);
}
