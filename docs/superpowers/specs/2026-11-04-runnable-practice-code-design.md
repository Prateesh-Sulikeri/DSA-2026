# Runnable practice code for DSA notes (short design)

## Intent
- Practice coding each problem from a blank file, run it, see pass/fail. Practice only, nothing else.

## Goals / non-goals
- Goals: one command runs a problem; tests tell pass or fail; no tools to install.
- Non-goals: build tools (Maven/Gradle/JUnit), timing/benchmarks, a runner script, a test framework.
- Anti-goal: the answer sitting in the file you practice in.

## Approaches
- A. One plain `.java` file per problem (chosen): simplest, zero setup.
- B. Practice + Reference files + run script: safer for the answer, but 3 files per problem. Not chosen.
- C. Maven/Gradle + JUnit: needs installs, adds files that don't help practice. Not chosen.

## Design (my calls, except A which is yours)
- Location: `code/<pattern file name without .md>/<ProblemName>.java`, e.g. `code/01 - Arrays & Hashing/MajorityElement.java`.
- File contents: a `public class MajorityElement` with `main` and test cases FIRST (source-file mode runs the first class), then `class Solution` as an empty stub (`return -1; // TODO`).
- Self-contained: tiny `check(name, actual, expected)` helper inside each file; prints ✔/✘ per case plus a summary, exits with code 1 on any failure.
- Run: `java "code/01 - Arrays & Hashing/MajorityElement.java"` (Java 26 runs source directly, no compile step, no `.class` files).
- Tests: examples from LeetCode plus the edge cases already listed in the note's **Edge cases** line.
- Answer stays in the note's collapsed Code callout only. To redo a problem: copy the code out, or `git checkout` the stub.
- Note link: each problem block gets a line `- **Practice:** ` + file path + run command.
- Workflow: update `CLAUDE.md` so "add a problem" also creates the stub file and the Practice line.
- First instance: Majority Element (LC 169), added and verified by running the stub (fails) and the pasted reference (passes).
- Left to the builder: exact test cases, helper formatting.

## Update 2026-11-04
- Layout changed: `static class Solution` is nested as the first member (SOLUTION header), tests below. Run command is `java <Name>.java` from the file's folder (the emoji in the full path breaks `java`).
