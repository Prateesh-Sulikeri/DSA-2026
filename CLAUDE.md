# DSA Interview Prep Notes

This folder holds my DSA notes for interview prep. The same notes serve two purposes:
1. **Learning:** writing up each pattern and problem the first time.
2. **Revision:** skimming quickly before an interview.

Every rule below serves both goals. All the important information is in the note, but it can be skimmed in seconds.

## Structure: one file per pattern

- Each pattern gets **one file**, and the problems for that pattern go inside it as sections.
- **One folder per pattern**, named `NN - Pattern Name/`. `NN` is the study order. Everything for that pattern lives inside it:
  ```
  📊 DSA/
  ├── CLAUDE.md
  ├── 00 - Master Index.md         ← tracks ALL patterns
  ├── 01 - Arrays & Hashing/       ← pattern WITH sub-topics
  │   ├── 00 - Index.md            ← one index for the whole pattern (all sub-topics)
  │   ├── 01 - Linear Scan/
  │   │   ├── notes/01 - Linear Scan.md
  │   │   ├── code/<ProblemName>.java
  │   │   └── pdfs/<Section>_Cheat_Sheet.pdf · _Revision_Sheet.pdf · _Detailed_Notes.pdf
  │   └── 02 - Two Pointers/
  │       ├── notes/02 - Two Pointers.md
  │       ├── code/
  │       └── pdfs/
  └── 02 - Sliding Window/         ← pattern WITHOUT sub-topics
      ├── 00 - Index.md
      ├── notes/02 - Sliding Window.md
      ├── code/
      └── pdfs/
  ```
- Pattern file: `NN - Pattern Name/notes/NN - Pattern Name.md` (for example `02 - Sliding Window/notes/02 - Sliding Window.md`).
- **Sub-topics:** a big pattern can be split into sub-topic folders `NN - Pattern/MM - Sub-topic/`, each with its own `notes/`, `code/`, `pdfs/`. Then the sub-topic file *is* the pattern file in every rule below (template, problems, PDFs). The pattern keeps a single `00 - Index.md` covering all its sub-topics, with a **Sub-topics** table and a Sub-topic column in **Problems**.
- `pdfs/` folders are git-ignored (generated output). Everything else is checked in.

### Two indexes
- **`00 - Master Index.md`** (DSA root) tracks progress across all patterns:
  - **Progress:** one row per pattern from the suggested order (plus a `↳` row per sub-topic): status, problem count, and ✅ / ⚠️ / ❌ counts, plus a Total row.
  - **Which pattern?:** the cross-pattern signal → pattern lookup.
  - **Redo queue:** every ❌ and ⚠️ problem, worst first.
  - **All problems:** every problem, with its pattern.
- **`NN - Pattern Name/00 - Index.md`** is the index for one pattern:
  - a back-link to the master index,
  - links to the notes, the practice code and the PDFs,
  - **Which technique?:** the signals inside this pattern,
  - **Problems:** with the practice file name, plus totals.
- Every pattern index has the same file name, so link to it with its path: `[[NN - Pattern Name/00 - Index|index]]`.
- Keep the two indexes in sync. The counts, confidence and redo queue in the master index must match the pattern indexes.
- If one problem's write-up gets too long for its pattern file (more than about 60 lines), move it to `NN - Pattern Name/notes/Problems/<Problem Name>.md` and link it from the pattern file with a short entry.
- A problem that fits several patterns goes under its **main** pattern. The others get a single-line link to it under **Related**.

### Suggested pattern order

```
01 Arrays & Hashing        08 Binary Tree (DFS/BFS)   16 Backtracking
   ↳ 01 Linear Scan        09 Binary Search Tree      17 Graphs (BFS/DFS)
   ↳ 02 Two Pointers       10 Heap / Top-K            18 Topological Sort
02 Sliding Window          11 Intervals               19 Union Find
03 Prefix Sum              12 Greedy                  20 Shortest Path
04 Binary Search           13 Trie                    21 1-D DP
05 Stack / Monotonic Stack 14 Bit Manipulation        22 2-D DP
06 Linked List             15 Math & Geometry         23 Advanced (Segment Tree, etc.)
07 Fast & Slow Pointers
```

Rename, merge or reorder these as the notes grow. Keep the numbering continuous.

## Templates (use these from now on)

The two templates live in `_templates/` and are the **source of truth**. Always copy them; never write a section layout from memory.

| Template | Use it for | How |
|----------|-----------|-----|
| `_templates/DSA pattern.md` | a new pattern (or sub-topic) notes file | Obsidian: new note → **Templates: Insert template**. Claude: copy the file, fill in `{{title}}` and today's date for `last_revised`. |
| `_templates/DSA problem.md` | each new problem under `## Problems` | Obsidian: cursor under `## Problems` → **Templates: Insert template**. Claude: copy the block and fill every field. |

If the layout ever needs to change, change the template file first, then this section.

### Pattern file
Sections in this order: frontmatter (`tags`, `status: learning | revising | confident`, `last_revised`) → `# Title` → **TL;DR** (What / When / Complexity + a bold **Rule:**) → **Recognition Signals** (incl. `✗ Not this when:`) → **Template** → **Variants** → **Problems** (easy → hard) → **Pitfalls** → **Related**. Leave out a section only if it truly doesn't apply.

### Problem block
A filled-in example of `_templates/DSA problem.md`:

````markdown
### LC 3 · Longest Substring Without Repeating Characters · 🟡 Medium
[Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) · Confidence: ⚠️

- **Key insight:** the single idea that cracks the problem (one line).
- **Approach:**
  1. Step
  2. Step
  3. Step
- **Brute → Optimal:** O(n³) check every substring → O(n) window + set.
- **Complexity:** O(n) time · O(min(n, charset)) space
- **Edge cases:** empty string, all the same character, all unique.
- **Clarifying questions:** ASCII only or full Unicode? Can the string be empty? Return the length or the substring?
- **Follow-ups:** at most k repeats allowed → same window, count map · input is a stream → keep last-seen indices.
- **Practice:** `<pattern folder>/code/<ProblemName>.java` · run: `java <ProblemName>.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> // solution
> ```
````

Field rules:
- **Difficulty:** 🟢 Easy · 🟡 Medium · 🔴 Hard
- **Confidence:** ✅ can solve cold · ⚠️ shaky, needs revisiting · ❌ couldn't solve, must redo. Update it on every revision pass.
- **Key insight** is required. It's the line I'll actually read during revision.
- Code always goes inside a **collapsed callout** (`> [!example]-`). That way a revision skim shows only the ideas, and the code is one click away.
- **Brute → Optimal** is optional. Include it when the jump between the two is itself worth remembering.
- **Clarifying questions** and **Follow-ups** go on every problem, one or two lines each. Clarifying = what to ask the interviewer before coding (input limits, duplicates, output format). Follow-ups = what they ask next, each with a short `→` answer.
- My study tracker (`D:\Coding Window\Roadmap`) reads these `- **Label:** text` lines to build its problem pages, so keep the bold label + colon format exactly.

## Writing style

- Bullets, not paragraphs. If a bullet needs more than 2 lines, split it up.
- End each concept with a bold **Rule:** one-liner, matching the style of the `🍵 Java` notes.
- Code: **Java**. Comment only the lines that aren't obvious. Use clear variable names (`left`/`right`, not `i`/`j`, when they mean window bounds).
- Use `→` for "leads to / becomes", and `✗` for "not this when".
- Prefer tables for comparisons (for example, variants side by side or BFS vs DFS).
- Use Obsidian `[[wikilinks]]` for links between notes and between patterns.
- Don't add filler or textbook history. If it won't help me in an interview, leave it out.

## Revision layers

The notes have three reading depths. They line up with the `handwritten-notes-pdf` skill:

| Layer | What to read | PDF |
|-------|--------------|-----|
| 5-min skim | **TL;DR** + **Rule** of every pattern | Cheat Sheet |
| 30-min revision | + Recognition Signals, Template, each problem's **Key insight** | Revision Sheet |
| Full study | Everything, including code | Detailed Notes |

So the TL;DR, Rule and Key insight lines must make sense **on their own**, without the rest of the note.

### PDF output
- Save the three PDFs of a pattern in `<pattern folder>/pdfs/`, named `<Section>_Cheat_Sheet.pdf`, `<Section>_Revision_Sheet.pdf`, `<Section>_Detailed_Notes.pdf`.
- Build from that pattern's `notes/` only; never mix several patterns into one PDF set.
- **Detailed Notes = a visual study guide**, hand-written by Claude, never the markdown re-typeset. For each problem: the question with an example → intuition (drawn) → why it works → a step-by-step trace table on an input that hits the tricky case → brute → optimal → code → mistakes and edge cases → ★ Rule.
- **Cheat Sheet = recall + self-test**, in this order: signal → move table, one line per problem with its key idea, a tiny trace per algorithm, the 3–6 core code lines, a ☐ mistakes checklist, then **Test yourself** questions with the answers on a separate last page. Full sentences, never shortened wording.
- Check every trace and answer by running it before it goes on the page.

## Instructions for Claude

When I ask you to add a problem or a pattern:
1. Work out the problem's main pattern and add it to that pattern's `notes/` file. If the pattern is new, create `NN - Pattern Name/` with `notes/`, `code/`, `pdfs/` and a `00 - Index.md` (copy the shape of `01 - Arrays & Hashing/00 - Index.md`, dropping the Sub-topics table if there are none), create the note from `_templates/DSA pattern.md`, and link the pattern in the master index's **Progress** table.
2. Insert the problem in difficulty order (easy → hard) and copy `_templates/DSA problem.md` and fill every field, including Clarifying questions and Follow-ups.
2a. Also create the runnable practice file `<pattern folder>/code/<ProblemName>.java`: a `public class <ProblemName>` whose FIRST member is `static class Solution` (empty stub, `return -1; // TODO`) under a `// ===== SOLUTION =====` header, then `main` + test cases (examples + the Edge cases) under `// ===== TESTS =====`. Solution goes on top so it's what you see first; it must be nested because `java File.java` runs the first top-level class. Self-contained, with `check`/`done` helpers (copy from `01 - Arrays & Hashing/01 - Linear Scan/code/MajorityElement.java`), ASCII `PASS`/`FAIL` output. The answer goes only in the note's collapsed Code callout, never in the practice file. Run the stub (must fail) and the reference (must pass) before finishing.
2b. Add the problem to **both indexes**:
  - **Pattern index** (`NN - Pattern Name/00 - Index.md`): add a row in **Problems** and update the totals. If the problem brings a new signal, add a row in **Which technique?**.
  - **Master index** (`00 - Master Index.md`): add a row in **All problems**, update that pattern's counts and the Total in **Progress**, and add it to the **Redo queue** if it is ❌ or ⚠️. If it is a new cross-pattern signal, add a row in **Which pattern?**.
  - Link straight to the problem heading with `[[NN - Pattern#<exact heading text>\|Short name]]`, never just to the file.
  - When a confidence changes on a revision pass, update it in both indexes and in the redo queue.
3. If the problem introduces a new variant or pitfall, also update **Variants**, **Pitfalls** or **Recognition Signals** in that pattern file.
4. Set `last_revised` in the frontmatter to today's date whenever the file meaningfully changes.
5. Don't rewrite my own wording in notes I've already written unless I ask. Point out mistakes instead of silently "fixing" them.
6. When explaining a solution, give the key insight first and then the steps. Keep it short.
