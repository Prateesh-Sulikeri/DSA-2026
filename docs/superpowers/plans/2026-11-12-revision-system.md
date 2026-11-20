# Revision System Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Make every problem revisable by its make-or-break detail, and define the three revision modes (start of session, weekly, day before) so that any session runs them the same way.

**Architecture:** Markdown-only changes to the Obsidian vault: a required `Gotcha` bullet in the problem template, `Added` / `Last quizzed` columns in both indexes, a root `00 - Revision Log.md`, and a `## Revision` section in `CLAUDE.md`. The "tests" are grep checks.

**Tech Stack:** Obsidian markdown, Git Bash (`grep`).

**Spec:** `docs/superpowers/specs/2026-11-12-revision-system-design.md`

## Global Constraints
- Gotchas are **copied** from the existing Pitfalls lines. Pitfalls stays unchanged (CLAUDE.md rule 5: don't rewrite the user's wording).
- Dates use `YYYY-MM-DD`. Backfill Added = `2026-11-04` and Last quizzed = `–`.
- Confidence: a miss drops one level (floor ❌). All gotchas right cold raises one level, **capped at ⚠️**. ✅ only after passing the practice stub cold.
- Day-before pass is ≤ 4 hrs: blocks 30 / 90 / 90 / 30 min.
- Day-before files: `00 - Interview Day/<Company>.md` (checked in) and `00 - Interview Day/pdfs/` (already git-ignored by `**/pdfs/`).
- Wikilinks to problems keep the exact heading text: `[[01 - Arrays & Hashing#<heading>\|Name]]`.
- Work on branch `revision-system`, not `main`.

## Review Focus
1. **Header and data columns out of step:** a table where the new columns are in the header but missing from a data row renders broken in Obsidian. Pinned by the column-count check in Task 3.
2. **Gotcha and Key insight confused:** a Gotcha that restates the Key insight defeats the purpose. Each Gotcha must name a concrete init value, update order or mandatory step. Task 2's check confirms that each Gotcha contains code or a named step.
3. **Master and pattern index disagree:** the counts, dates and confidence marks must match. Pinned by the diff check in Task 3.
4. **"Last pattern" is ambiguous on the first ever quiz:** with no quiz yet, every Last quizzed is `–`. The rule must fall back to the most recent Added. Stated in Task 1.
5. **Weekly pass with nothing new that week:** the scope must still include all ❌ problems, so the pass is never empty. Stated in Task 1.

---

### Task 1: CLAUDE.md, the template and the revision rules

**Files:**
- Modify: `CLAUDE.md` (problem block template ~line 115, field rules ~line 134, index description ~line 41, instructions 2b ~line 173; new section after `## Revision layers`)

- [ ] **Step 1: Failing check**
  Run: `grep -c "Gotcha" CLAUDE.md; grep -c "^## Revision$" CLAUDE.md`
  Expected: `0` and `0`
- [ ] **Step 2: Edit the problem block template**
  Add `- **Gotcha:** the exact detail that breaks the solution if you get it wrong (1–3 lines: an init value, an update order, a mandatory pass).` directly under `- **Key insight:**`. The example must use LC 3: `` `left = max(left, last[c] + 1)`. Never move `left` backwards. ``
- [ ] **Step 3: Edit the field rules**
  Add: `**Gotcha** is required. It's what revision quizzes test. Copy it from Pitfalls when one already covers it.`
- [ ] **Step 4: Edit the index descriptions and instruction 2b**
  The pattern **Problems** table and the master **All problems** table both carry `Added` and `Last quizzed` columns. Set Added to today when adding a problem.
- [ ] **Step 5: Add the `## Revision` section** after `## Revision layers`. It contains:
  - The 3-mode table from the spec (mode / who / scope / length / format).
  - **Last pattern** = the pattern with the most recent Last quizzed or Added date (falls back to Added when nothing has been quizzed).
  - **Weekly scope** = problems with Added or Last quizzed in the past 7 days **plus all ❌**, then one ❌ stub re-solved cold.
  - **Quiz mechanics:** one question at a time, built from Gotcha + Edge cases, weighted ❌ > ⚠️ > ✅, no code in questions, show the correct Gotcha line after each answer.
  - The confidence rules from Global Constraints.
  - **After every quiz:** update Last quizzed and confidence in both indexes and the redo queue, and add a row to `00 - Revision Log.md`.
  - **Day before:** the four blocks (30 / 90 / 90 / 30), the `00 - Interview Day/` files, unseen company problems listed separately and never put into the day-before plan, the PDF built in handwritten-notes-pdf style with full sentences and every answer checked, and a note that this is the only PDF that spans patterns.
  - Add `00 - Revision Log.md` and `00 - Interview Day/` to the folder tree near the top.
- [ ] **Step 6: Passing check**
  Run: `grep -c "Gotcha" CLAUDE.md; grep -c "^## Revision$" CLAUDE.md; grep -c "Last quizzed" CLAUDE.md`
  Expected: ≥ 3, `1`, ≥ 2
- [ ] **Step 7: Commit**
  `git checkout -b revision-system && git add CLAUDE.md docs/superpowers && git commit -m "Add Gotcha field and revision modes to CLAUDE.md"`

### Task 2: Backfill the Gotchas in the Arrays note

**Files:**
- Modify: `01 - Arrays & Hashing/notes/01 - Arrays & Hashing.md` (Key insight lines 63, 91, 119, 151; frontmatter `last_revised`)

**Interfaces:**
- Consumes: the Gotcha format from Task 1.

- [ ] **Step 1: Failing check**
  Run: `grep -c "^- \*\*Gotcha:\*\*" "01 - Arrays & Hashing/notes/01 - Arrays & Hashing.md"`
  Expected: `0`
- [ ] **Step 2: Insert one Gotcha under each Key insight**, copied from the Pitfalls section:
  - LC 169: the `count == 0` check comes **before** the increment/decrement, or the wrong candidate is kept.
  - LC 53: initialise `best = nums[0]`, not `0`, or all-negative arrays are wrong. Update `best` on every element.
  - LC 152: save both `maxP` and `minP` in temps before overwriting either. Don't special-case zero; the `x` option restarts the run.
  - LC 229: check `x == c1` / `x == c2` **before** the `count == 0` replacements. The verify pass for > n/3 is mandatory.
- [ ] **Step 3: Set `last_revised: 2026-11-12`** in the frontmatter.
- [ ] **Step 4: Passing checks**
  Run: `grep -c "^- \*\*Gotcha:\*\*" <note>` → `4`.
  Run: `grep "^- \*\*Gotcha:\*\*" <note> | grep -vc '`'` → `0` (every Gotcha has a code token).
  Run: `git diff --stat` → the Pitfalls section is unchanged (only + lines and the frontmatter line).
- [ ] **Step 5: Commit** `git commit -am "Backfill Gotcha lines for Arrays & Hashing problems"`

### Task 3: Index columns and the revision log

**Files:**
- Modify: `01 - Arrays & Hashing/00 - Index.md` (Problems table)
- Modify: `00 - Master Index.md` (All problems table, `last_revised`)
- Create: `00 - Revision Log.md`

**Interfaces:**
- Produces: the column order `| # | Problem | Technique | Diff | Confidence | Added | Last quizzed | Practice file |` (pattern index) and `| # | Problem | Pattern | Technique | Diff | Confidence | Added | Last quizzed |` (master). The log's columns are `| Date | Mode | Pattern(s) | Problems | Missed gotchas | Confidence changes |`.

- [ ] **Step 1: Failing check**
  Run: `grep -c "Last quizzed" "00 - Master Index.md" "01 - Arrays & Hashing/00 - Index.md"; ls "00 - Revision Log.md"`
  Expected: `0`, `0`, not found
- [ ] **Step 2: Add the two columns** to both tables. Backfill the 4 rows with `2026-11-04 | –`. Set `last_revised: 2026-11-12` on both index files.
- [ ] **Step 3: Create `00 - Revision Log.md`** with frontmatter `tags: [dsa, index, revision-log]`, a back-link `← [[00 - Master Index|Master Index]]`, a one-line purpose ("one row per quiz, newest first"), and the empty table header. Add a link to it in the Master Index under the Redo queue.
- [ ] **Step 4: Passing checks**
  - Column counts: every table row in both files has the same number of `|` as its header.
    Run: `awk -F'|' '/^\|/{print NF}' "00 - Master Index.md" | sort | uniq -c`. Expected: one count per table, and no stray values inside the All problems block.
  - Sync: the problem/confidence/added values match between the two indexes for all 4 rows.
  - Run: `grep -c "Revision Log" "00 - Master Index.md"` → `1`
- [ ] **Step 5: Commit**
  `git add -A && git commit -m "Add Added/Last quizzed columns and revision log"`
