# PRD 05: Battery and Performance Modes

## Summary

Introduce configurable battery/performance modes to balance responsiveness and runtime based on user context.

## Problem

Users have different priorities: some want maximum battery life, others want the fastest interactions. Current behavior is mostly fixed.

## Goals

- Offer clear mode choices with predictable tradeoffs.
- Extend battery runtime in low-power profiles.
- Preserve responsive experience in performance profile.

## Non-Goals

- Dynamic CPU governor changes outside supported ESP32-C3 capabilities.
- Background multitasking features.

## User Stories

- As a commuter, I want a battery saver mode that lasts longer.
- As a power user, I want snappier interactions even if battery drains faster.
- As any user, I want to understand mode impact before switching.

## Functional Requirements

1. Add mode selector in Settings:
   - Battery Saver
   - Balanced (default)
   - Performance
2. Tune each mode across:
   - Refresh aggressiveness
   - Sleep timeout
   - WiFi auto-disconnect behavior
   - Cache warm-up strategy on boot
3. Show estimated impact text for each mode.
4. Persist mode and apply at boot.

## Success Metrics

- Battery Saver mode yields measurable runtime gain in benchmark scenario.
- Balanced mode remains within existing UX expectations.
- Less than 5% of users revert from chosen mode within first 24 hours.

## Risks

- Too many knobs can create inconsistent UX.
- Aggressive saver settings may feel sluggish.

## Rollout Plan

1. Core mode scaffolding and persistence.
2. Tuning pass with test matrix.
3. User-facing copy and defaults validation.
