# Git Workflow for Inkforge Firmware

## Goal

Run a clean fork workflow so we can move quickly while staying easy to rebase on upstream CrossPoint.

## Current State

- Local repository: `crosspoint-reader`
- Tracking remote: `origin` -> official CrossPoint repository

## Recommended Remote Layout

1. Keep official CrossPoint as `upstream`.
2. Set Karl's fork as `origin`.

Use these commands once your fork exists:

```bash
git remote rename origin upstream
git remote add origin <YOUR_FORK_GIT_URL>
git fetch --all --prune
```

## Branch Strategy

- `main`: stable branch for the fork
- `feature/*`: active implementation work
- `release/*`: optional release hardening

Examples:

- `feature/reading-ux-presets`
- `feature/library-intelligence`
- `feature/battery-performance-modes`
- `feature/context-button-profiles`

## PR Rules

- Small PRs, one feature stream per branch.
- Require passing local build before merge:

```bash
pio run
```

- Use squash merge to keep `main` readable.

## Upstream Sync Cadence

Run weekly (or before major releases):

```bash
git fetch upstream
git switch main
git rebase upstream/master
```

Resolve conflicts in small batches, then run full firmware build.

## Tagging and Releases

Use tags with fork prefix:

- `inkforge-v0.1.0`
- `inkforge-v0.2.0`

Release notes should include:

- New features
- Known limitations
- Upstream commit baseline
