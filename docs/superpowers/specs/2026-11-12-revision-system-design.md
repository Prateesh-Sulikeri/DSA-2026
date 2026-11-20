# Revision System: Design

Date: 2026-11-12 · Status: draft, awaiting approval

## Intent
- I remember the algorithm but forget the **small, problem-specific details** that make or break the solution.
- So every revision pass is built around those details ("gotchas") and tests them by recall, never by re-reading.
- Three situations, each with its own pass: **start of a session**, **weekly**, **the day before an interview**.

## Goals
- Every problem carries its make-or-break detail next to its Key insight.
- "Last topic" and "this week's stack" can be found from the indexes without guessing.
- Confidence marks move based on quiz results, and stay in sync across both indexes and the redo queue.
- The day-before pass fits in **≤ 4 hrs** at any number of patterns, tailored to the company.

## Non-goals
- No spaced-repetition algorithm or Obsidian plugin.
- No regenerating the existing Arrays PDFs as part of this change.
- No separate gotcha/flashcard files.

## Anti-goals
- A pass that is just re-reading summaries (that's what already fails).
- Rewriting the user's existing wording (CLAUDE.md rule 5): gotchas are **copied** from Pitfalls, and Pitfalls stays.
- Learning new problems the day before.

## Approaches
| | Approach | Trade-off | |
|-|----------|-----------|-|
| A | Gotcha field inline in each problem block; Added / Last quizzed columns in indexes; one revision log | One extra field per problem | **Picked** |
| B | Separate `notes/Gotchas.md` Q&A bank per pattern | Duplicates notes, drifts, gotchas invisible on a skim | |
| C | Obsidian Spaced Repetition cards inline | Plugin dependency, overlaps with Claude quizzing, clutters notes | |

Picked A: one source of truth, reuses existing Pitfalls, fits one-file-per-pattern.

## Decided

### Note changes
- Problem block template gets a required `- **Gotcha:**` bullet directly under **Key insight**: 1–3 lines, the exact detail that breaks the solution (an init value, an update order, a mandatory pass).
- Backfill the 4 existing problems from the current Pitfalls lines (copied verbatim where possible).

### Index changes
- Pattern index **Problems** table and master **All problems** table get two columns: **Added** and **Last quizzed** (`YYYY-MM-DD`).
- Backfill Added = 2026-11-04 for the 4 existing problems; Last quizzed = `–`.

### Revision log
- New `00 - Revision Log.md` at the DSA root, newest first:
  `| Date | Mode | Pattern(s) | Problems | Missed gotchas | Confidence changes |`

### The three modes (written into CLAUDE.md as a "Revision" section)
| Mode | Who runs it | Scope | Length | Format |
|------|-------------|-------|--------|--------|
| Start of session | Claude quizzes | The last pattern worked on (most recent Added / Last quizzed) | ~5 min, 4–6 questions | Gotchas + edge cases, weighted ❌ > ⚠️ > ✅ |
| Weekly | Claude quizzes | Every problem Added or Last quizzed in the past 7 days, plus all ❌ | ~20–30 min | Same, plus re-solving one ❌ stub cold |
| Day before | User alone | Company-tagged patterns in depth, all others recognition only | ≤ 4 hrs | One printable PDF |

### Day-before blocks
1. Recognition (30 min): the "Which pattern?" table as a quiz.
2. Gotchas for the company's patterns (90 min): answers on the back pages.
3. Re-solve cold (90 min): practice stubs for the company-frequent problems in the notes, plus everything still ❌.
4. Misses only (30 min): re-read the gotchas missed in blocks 2–3. Nothing new.

## Claude's calls (check these)
- **Quiz mechanics:** one question at a time; answers in words or a line of code; no code shown in questions; Claude shows the correct gotcha line after each answer.
- **Confidence rules:** a miss drops the problem one level (floor ❌). Getting all its gotchas right cold raises it one level, **capped at ⚠️**. Reaching ✅ needs the practice stub passed cold, since ✅ means "can solve cold".
- **After every quiz:** update Last quizzed, confidence in both indexes + redo queue, and add a log row.
- **Day-before files:** `00 - Interview Day/<Company>.md` (checked in) maps the company list to problems in the notes and lists the unseen ones. The PDF goes in `00 - Interview Day/pdfs/` (git-ignored), built with the handwritten-notes-pdf style, full sentences, every answer checked. The only PDF that spans patterns.
- **Unseen company problems** are listed separately with their pattern's gotchas. They go into weekly passes if the research is done early enough, never into the day-before plan.
- **This doc's location:** `docs/superpowers/specs/` in the vault. Not committed until you say so.

## Left to the builder
- Exact wording of the CLAUDE.md Revision section and the quiz prompts.
- Layout of the day-before PDF (built later, once a company list exists).
