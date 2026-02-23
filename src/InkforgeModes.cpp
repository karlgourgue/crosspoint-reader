#include "InkforgeModes.h"

namespace InkforgeModes {
void applyReaderPreset(CrossPointSettings& settings, const uint8_t preset) {
  switch (preset) {
    case CrossPointSettings::PRESET_COMPACT:
      settings.fontFamily = CrossPointSettings::NOTOSANS;
      settings.fontSize = CrossPointSettings::SMALL;
      settings.lineSpacing = CrossPointSettings::TIGHT;
      settings.screenMargin = 5;
      settings.extraParagraphSpacing = 0;
      break;
    case CrossPointSettings::PRESET_CLASSIC:
      settings.fontFamily = CrossPointSettings::BOOKERLY;
      settings.fontSize = CrossPointSettings::MEDIUM;
      settings.lineSpacing = CrossPointSettings::NORMAL;
      settings.screenMargin = 10;
      settings.extraParagraphSpacing = 1;
      break;
    case CrossPointSettings::PRESET_AIRY:
      settings.fontFamily = CrossPointSettings::BOOKERLY;
      settings.fontSize = CrossPointSettings::MEDIUM;
      settings.lineSpacing = CrossPointSettings::WIDE;
      settings.screenMargin = 15;
      settings.extraParagraphSpacing = 1;
      break;
    case CrossPointSettings::PRESET_LARGE_PRINT:
      settings.fontFamily = CrossPointSettings::NOTOSANS;
      settings.fontSize = CrossPointSettings::EXTRA_LARGE;
      settings.lineSpacing = CrossPointSettings::WIDE;
      settings.screenMargin = 10;
      settings.extraParagraphSpacing = 1;
      break;
    case CrossPointSettings::PRESET_NIGHT_COMFORT:
      settings.fontFamily = CrossPointSettings::BOOKERLY;
      settings.fontSize = CrossPointSettings::LARGE;
      settings.lineSpacing = CrossPointSettings::NORMAL;
      settings.screenMargin = 20;
      settings.extraParagraphSpacing = 1;
      break;
    default:
      break;
  }
}

void applyRefreshMode(CrossPointSettings& settings, const uint8_t refreshMode) {
  switch (refreshMode) {
    case CrossPointSettings::REFRESH_MODE_FULL:
      settings.refreshFrequency = CrossPointSettings::REFRESH_1;
      break;
    case CrossPointSettings::REFRESH_MODE_BALANCED:
      settings.refreshFrequency = CrossPointSettings::REFRESH_10;
      break;
    case CrossPointSettings::REFRESH_MODE_AGGRESSIVE:
      settings.refreshFrequency = CrossPointSettings::REFRESH_30;
      break;
    default:
      break;
  }
}

void applyPerformanceMode(CrossPointSettings& settings, const uint8_t performanceMode) {
  switch (performanceMode) {
    case CrossPointSettings::PERF_BATTERY_SAVER:
      settings.sleepTimeout = CrossPointSettings::SLEEP_5_MIN;
      settings.hideBatteryPercentage = CrossPointSettings::HIDE_ALWAYS;
      settings.refreshMode = CrossPointSettings::REFRESH_MODE_AGGRESSIVE;
      applyRefreshMode(settings, settings.refreshMode);
      settings.fadingFix = 0;
      break;
    case CrossPointSettings::PERF_BALANCED:
      settings.sleepTimeout = CrossPointSettings::SLEEP_15_MIN;
      settings.hideBatteryPercentage = CrossPointSettings::HIDE_READER;
      settings.refreshMode = CrossPointSettings::REFRESH_MODE_BALANCED;
      applyRefreshMode(settings, settings.refreshMode);
      settings.fadingFix = 0;
      break;
    case CrossPointSettings::PERF_PERFORMANCE:
      settings.sleepTimeout = CrossPointSettings::SLEEP_30_MIN;
      settings.hideBatteryPercentage = CrossPointSettings::HIDE_NEVER;
      settings.refreshMode = CrossPointSettings::REFRESH_MODE_FULL;
      applyRefreshMode(settings, settings.refreshMode);
      settings.fadingFix = 1;
      break;
    default:
      break;
  }
}

void applyControlProfile(CrossPointSettings& settings, const uint8_t controlProfile) {
  switch (controlProfile) {
    case CrossPointSettings::CONTROL_DEFAULT:
      settings.sideButtonLayout = CrossPointSettings::PREV_NEXT;
      settings.longPressChapterSkip = 1;
      settings.shortPwrBtn = CrossPointSettings::IGNORE;
      settings.frontButtonBack = CrossPointSettings::FRONT_HW_BACK;
      settings.frontButtonConfirm = CrossPointSettings::FRONT_HW_CONFIRM;
      settings.frontButtonLeft = CrossPointSettings::FRONT_HW_LEFT;
      settings.frontButtonRight = CrossPointSettings::FRONT_HW_RIGHT;
      break;
    case CrossPointSettings::CONTROL_LEFT_HANDED:
      settings.sideButtonLayout = CrossPointSettings::NEXT_PREV;
      settings.longPressChapterSkip = 1;
      settings.shortPwrBtn = CrossPointSettings::IGNORE;
      settings.frontButtonBack = CrossPointSettings::FRONT_HW_RIGHT;
      settings.frontButtonConfirm = CrossPointSettings::FRONT_HW_LEFT;
      settings.frontButtonLeft = CrossPointSettings::FRONT_HW_CONFIRM;
      settings.frontButtonRight = CrossPointSettings::FRONT_HW_BACK;
      break;
    case CrossPointSettings::CONTROL_ONE_HAND_COMMUTE:
      settings.sideButtonLayout = CrossPointSettings::PREV_NEXT;
      settings.longPressChapterSkip = 0;
      settings.shortPwrBtn = CrossPointSettings::PAGE_TURN;
      settings.frontButtonBack = CrossPointSettings::FRONT_HW_BACK;
      settings.frontButtonConfirm = CrossPointSettings::FRONT_HW_CONFIRM;
      settings.frontButtonLeft = CrossPointSettings::FRONT_HW_LEFT;
      settings.frontButtonRight = CrossPointSettings::FRONT_HW_RIGHT;
      break;
    case CrossPointSettings::CONTROL_MINIMAL:
      settings.sideButtonLayout = CrossPointSettings::PREV_NEXT;
      settings.longPressChapterSkip = 0;
      settings.shortPwrBtn = CrossPointSettings::SLEEP;
      settings.statusBar = CrossPointSettings::NONE;
      settings.frontButtonBack = CrossPointSettings::FRONT_HW_BACK;
      settings.frontButtonConfirm = CrossPointSettings::FRONT_HW_CONFIRM;
      settings.frontButtonLeft = CrossPointSettings::FRONT_HW_LEFT;
      settings.frontButtonRight = CrossPointSettings::FRONT_HW_RIGHT;
      break;
    default:
      break;
  }
}
}  // namespace InkforgeModes
