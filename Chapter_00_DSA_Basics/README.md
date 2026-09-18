# 📗 Chapter 00 — DSA Basics

One deep pass over every interview-relevant data structure.
Build it → learn its patterns → implement them.

📄 Roadmap: [PLAN.md](PLAN.md) · **Cadence:** min. 1 data structure / day

---

## 📊 Progress

A structure counts as ✅ **Done** only when all three files are complete.

| Day | Structure | `<Name>.cpp` | `Patterns.md` | `Patterns.cpp` | Status |
| :-: | :-- | :-: | :-: | :-: | :-- |
| 1 | Arrays | ⬜ | ✅ | ⬜ | 🚧 In progress |
| 2 | Strings | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 3 | Hashing | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 4 | Linked List | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 5 | Stacks | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 6 | Queues & Deque | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 7 | Heap / Priority Queue | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 8 | Binary Tree | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 9 | Binary Search Tree | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 10 | Trie | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 11 | Graphs | ⬜ | ⬜ | ⬜ | ⬜ Not started |
| 12 | Union-Find (DSU) | ⬜ | ⬜ | ⬜ | ⬜ Not started |

**0 / 12 complete**

---

## 🗂️ Directory layout

Every structure gets the same four-part treatment:

```
Chapter_XX_<Name>/
├── <Name>.cpp        the structure + its operations (no patterns)
├── Patterns.md      pattern theory: trigger, idea, invariant, variations, traps
└── Patterns.cpp      each pattern as its own class, with variations
```

| File | Purpose | Author |
| :-- | :-- | :-- |
| `<Name>.cpp` | Interview-level implementation of the structure and every operation, with complexity and edge cases. | Prateesh |
| `Patterns.md` | The theory sheet — what each pattern is, when to reach for it, when not to, and the classic mistakes. Doubles as the revision sheet. | Claude |
| `Patterns.cpp` | Every pattern implemented as a class + its variations. `main()` just runs the demos. | Prateesh |

---

## 🧭 Day log

| Date | Structure | Notes |
| :-- | :-- | :-- |
| 2026-09-17 | Arrays | `Patterns.md` written (11 patterns). `Arrays.cpp` + `Patterns.cpp` scaffolded, awaiting implementation. |
| 2026-09-18 | Arrays | `Arrays.cpp` Parts A & B implemented (basics + the STL operations toolkit). Audited: builds clean under `-Wall -Wextra`, output correct. Audited, fixed, re-audited: Part B (B.1-B.10) now complete and building clean under `-Wall -Wextra`. Prateesh fixed B.3/B.5/B.9; on his request Claude wrote the B.4 two-case reallocation demo, the B.8/B.9 hit-and-miss lookups, and the B.10 `unique`/`erase` split. No `FIXME:` left in the file. Part C (passing to functions) implemented: by-value / by-ref / const-ref, all three demoed against one vector; builds clean under `-Wall`, output proves which call mutates the caller. Review raised one `FIXME:` -- the const-ref demo was muddied by the preceding by-ref mutation -- which Prateesh fixed by resetting `v[0]` before the const-ref call; re-audited, output now reads unambiguously and no `FIXME:` is left in the file. Part D (`DynamicArray`) implemented: raw owning `int*` + `sz`/`cap`, doubling growth, `push_back`/`pop_back`/`at`/`insert`/`erase`/`clear`/`print`. Builds clean under `-Wall -Wextra`; growth, shift and throw paths verified under `-fsanitize=address,undefined`. Review raised one `BUG:` -- `DynamicArray(0, val)` leaves `cap == 0`, and doubling has a fixed point at zero, so the next `push_back` writes past a zero-length buffer (ASan-confirmed heap-buffer-overflow) -- plus `FIXME:`s on the dead `increaseCapacity` parameter, the duplicated `push_back` branches, the pointless realloc in `clear()`, the missing `const` on `print()`/`at()`, and the still-open Rule of Three. The demo in `main()` was flagged separately: it never crosses a capacity boundary, so the doubling is never shown, and its prints are unlabelled. Teaching comments (invariants, amortized-O(1) argument, reference invalidation, traps) written into the file; fixes and the rewritten D.1-D.7 demo are his to write. Outstanding: the B.4 and Part D `THINK` answers, the `BUG:`/`FIXME:` set above, and the demo rewrite. |

---

## ⚙️ Compiling

```bash
g++ -std=c++17 -Wall <file>.cpp -o out && ./out
```
