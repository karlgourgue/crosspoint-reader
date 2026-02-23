#pragma once

#include <functional>

#include "activities/Activity.h"

class ButtonTestActivity final : public Activity {
 private:
  const std::function<void()> onBack;

 public:
  explicit ButtonTestActivity(GfxRenderer& renderer, MappedInputManager& mappedInput, const std::function<void()>& onBack)
      : Activity("ButtonTest", renderer, mappedInput), onBack(onBack) {}
  void onEnter() override;
  void onExit() override;
  void loop() override;
  void render(Activity::RenderLock&&) override;
};
