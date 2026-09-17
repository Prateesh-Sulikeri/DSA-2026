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

---

## ⚙️ Compiling

```bash
g++ -std=c++17 -Wall <file>.cpp -o out && ./out
```
