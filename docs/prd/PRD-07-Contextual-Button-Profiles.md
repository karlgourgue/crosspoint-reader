# PRD 07: Contextual Button Profiles

## Summary

Add context-aware button mapping with multi-gesture bindings and safe profile switching.

## Problem

Static button behavior limits ergonomics, especially across reading, menus, and one-handed use cases.

## Goals

- Make controls customizable by context.
- Support tap, long press, and hold repeat actions.
- Prevent accidental lock-out through safety constraints.

## Non-Goals

- Arbitrary macro scripting.
- Full gesture recognition beyond button events.

## User Stories

- As a left-handed user, I want a profile that feels natural for my grip.
- As a reader, I want long-press actions for chapter jumps.
- As a cautious user, I want guaranteed recovery if mappings are misconfigured.

## Functional Requirements

1. Introduce action abstraction layer:
   - `next_page`, `prev_page`, `menu`, `back`, `home`, `refresh`, `sleep`, etc.
2. Enable per-context mapping tables:
   - Reader
   - Menus
   - Keyboard entry
   - WiFi/File transfer screens
3. Support event types:
   - Tap
   - Long press
   - Hold repeat
4. Add built-in profiles:
   - Default
   - Left-handed
   - One-hand commute
   - Minimal
5. Add safety rails:
   - Reserved escape path
   - Confirm before remapping critical actions
   - Reset current context / reset all
6. Add button test screen showing live event detection.

## Success Metrics

- 70% of beta users keep a non-default profile after one week.
- Reduced accidental action reports in reader flow.
- No unrecoverable navigation lockouts.

## Risks

- Input complexity may increase bug surface area.
- Profile UX can become confusing without strong defaults.

## Rollout Plan

1. Action layer + context mapping.
2. Gesture events and repeat behavior.
3. Profile UI, test screen, and reset flows.
