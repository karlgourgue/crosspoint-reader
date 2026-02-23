#include "ButtonTestActivity.h"

#include <GfxRenderer.h>
#include <I18n.h>

#include "MappedInputManager.h"
#include "components/UITheme.h"
#include "fontIds.h"

void ButtonTestActivity::onEnter() {
  Activity::onEnter();
  requestUpdate();
}

void ButtonTestActivity::onExit() { Activity::onExit(); }

void ButtonTestActivity::loop() {
  if (mappedInput.wasPressed(MappedInputManager::Button::Back)) {
    onBack();
    return;
  }

  if (mappedInput.wasAnyPressed() || mappedInput.wasAnyReleased()) {
    requestUpdate();
  }
}

void ButtonTestActivity::render(Activity::RenderLock&&) {
  renderer.clearScreen();

  const auto pageWidth = renderer.getScreenWidth();
  renderer.drawCenteredText(UI_12_FONT_ID, 15, tr(STR_BUTTON_TEST), true, EpdFontFamily::BOLD);

  struct Row {
    const char* label;
    MappedInputManager::Button button;
  };

  const Row rows[] = {
      {"Back", MappedInputManager::Button::Back},       {"Confirm", MappedInputManager::Button::Confirm},
      {"Left", MappedInputManager::Button::Left},       {"Right", MappedInputManager::Button::Right},
      {"Side Up", MappedInputManager::Button::Up},      {"Side Down", MappedInputManager::Button::Down},
      {"Power", MappedInputManager::Button::Power},     {"Page Back", MappedInputManager::Button::PageBack},
      {"Page Fwd", MappedInputManager::Button::PageForward},
  };

  int y = 45;
  for (const auto& row : rows) {
    renderer.drawText(UI_10_FONT_ID, 20, y, row.label);
    const bool pressed = mappedInput.isPressed(row.button);
    const char* state = pressed ? tr(STR_STATE_ON) : tr(STR_STATE_OFF);
    const int stateWidth = renderer.getTextWidth(UI_10_FONT_ID, state);
    renderer.drawText(UI_10_FONT_ID, pageWidth - 20 - stateWidth, y, state);
    y += 24;
  }

  const auto labels = mappedInput.mapLabels(tr(STR_BACK), "", "", "");
  GUI.drawButtonHints(renderer, labels.btn1, labels.btn2, labels.btn3, labels.btn4);

  renderer.displayBuffer();
}
