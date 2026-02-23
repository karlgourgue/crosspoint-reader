#include "InkforgeProfile.h"

namespace InkforgeProfile {
void applyV1Defaults(CrossPointSettings& settings) {
  // PRD-03: reading defaults
  settings.fontFamily = CrossPointSettings::BOOKERLY;
  settings.fontSize = CrossPointSettings::LARGE;
  settings.lineSpacing = CrossPointSettings::WIDE;
  settings.screenMargin = 10;
  settings.hyphenationEnabled = 1;
  settings.bionicReadingMode = 1;
  settings.embeddedStyle = 1;

  // PRD-05: balanced power/performance defaults
  settings.refreshFrequency = CrossPointSettings::REFRESH_10;
  settings.sleepTimeout = CrossPointSettings::SLEEP_15_MIN;
  settings.hideBatteryPercentage = CrossPointSettings::HIDE_READER;
  settings.uiTheme = CrossPointSettings::LYRA;

  // PRD-07: control defaults
  settings.sideButtonLayout = CrossPointSettings::PREV_NEXT;
  settings.longPressChapterSkip = 1;
  settings.frontButtonBack = CrossPointSettings::FRONT_HW_BACK;
  settings.frontButtonConfirm = CrossPointSettings::FRONT_HW_CONFIRM;
  settings.frontButtonLeft = CrossPointSettings::FRONT_HW_LEFT;
  settings.frontButtonRight = CrossPointSettings::FRONT_HW_RIGHT;
}
}  // namespace InkforgeProfile
