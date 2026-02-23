#include "InkforgeProfile.h"

#include "InkforgeModes.h"

namespace InkforgeProfile {
void applyV1Defaults(CrossPointSettings& settings) {
  // PRD-03: reading defaults
  settings.readerPreset = CrossPointSettings::PRESET_CLASSIC;
  InkforgeModes::applyReaderPreset(settings, settings.readerPreset);
  settings.hyphenationEnabled = 1;
  settings.bionicReadingMode = 1;
  settings.embeddedStyle = 1;

  // PRD-05: balanced power/performance defaults
  settings.performanceMode = CrossPointSettings::PERF_BALANCED;
  InkforgeModes::applyPerformanceMode(settings, settings.performanceMode);
  settings.uiTheme = CrossPointSettings::LYRA;

  // PRD-07: control defaults
  settings.controlProfile = CrossPointSettings::CONTROL_DEFAULT;
  InkforgeModes::applyControlProfile(settings, settings.controlProfile);
}
}  // namespace InkforgeProfile
