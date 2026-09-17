# 🗺️ Chapter 00 — DSA Basics: The Plan

> **Purpose of this section:** one deep, hands-on pass over every data structure
> that matters in interviews. Build the structure, learn its patterns, write the
> code yourself. This is the foundation round — the problem-solving sprint
> (Chapter_01 and above) sits on top of it.

**Cadence:** minimum **1 data structure per day** → 12 structures ≈ 12 working days.

---

## 📐 How each day works

Every `Chapter_XX_<Name>/` directory gets the same four things:

| File | What goes in it | Who writes it |
| :-- | :-- | :-- |
| `<Name>.cpp` | The structure itself + its operations. Interview-level implementation, complexity of each op, edge cases. **No patterns here.** | Prateesh |
| `Patterns.md` | Every pattern for this structure: name, recognition trigger, when *not* to use, core idea + invariant, complexity, variations, classic mistakes. | **Claude** |
| `Patterns.cpp` | Each pattern implemented — **one class per pattern** — plus its meaningful variations. `main()` stays clean: instantiate, run demos. | Prateesh |
| *(tracked in)* `README.md` | Progress. A structure is ✅ only when all three files are done. | Claude |

**Definition of done for a day:**
1. `<Name>.cpp` compiles, runs, and demonstrates every operation.
2. `Patterns.md` read and understood — it's the revision sheet.
3. `Patterns.cpp` compiles and every pattern class has at least one variation.

---

## 🎯 The 12 Data Structures

Grouped into four tiers that mirror the later 4-week sprint.

| Day | Structure | Directory | Tier |
| :-: | :-- | :-- | :-- |
| 1 | Arrays | `Chapter_01_Arrays` | Core |
| 2 | Strings | `Chapter_02_Strings` | Core |
| 3 | Hashing | `Chapter_03_Hashing` | Core |
| 4 | Linked List | `Chapter_04_Linked_List` | Structural |
| 5 | Stacks | `Chapter_05_Stacks` | Structural |
| 6 | Queues & Deque | `Chapter_06_Queues` | Structural |
| 7 | Heap / Priority Queue | `Chapter_07_Heap` | Structural |
| 8 | Binary Tree | `Chapter_08_Binary_Tree` | Trees |
| 9 | Binary Search Tree | `Chapter_09_BST` | Trees |
| 10 | Trie | `Chapter_10_Trie` | Trees |
| 11 | Graphs | `Chapter_11_Graphs` | Advanced |
| 12 | Union-Find (DSU) | `Chapter_12_Union_Find` | Advanced |

---

## 🔴 TIER 1 — CORE (Days 1–3)

### Day 1 · Arrays → `Chapter_01_Arrays`
**`Arrays.cpp`** — static array vs `vector`; vector internals (size vs capacity,
reallocation, iterator invalidation, `reserve`); core ops and their real cost;
2D vectors; the STL toolkit (`sort`, `reverse`, `accumulate`, `max_element`,
`find`, `count`, `lower_bound`/`upper_bound`, `unique`+`erase`); passing
semantics — by value vs `&` vs `const&`.

**Patterns** — prefix sum (1D + 2D); Kadane's; two pointers (opposite ends);
fast/slow write pointer (in-place removal); fixed sliding window; variable
sliding window; binary search; Dutch national flag; rotation by reversal;
cyclic sort / index-as-hash; XOR tricks.

### Day 2 · Strings → `Chapter_02_Strings`
**`Strings.cpp`** — `std::string` internals (SSO, capacity, why `+=` in a loop
is a trap); construction, `substr`, `find`, `compare`; `stringstream` for
building and splitting; char arithmetic and the `'a'` offset; `stoi`/`to_string`;
in-place vs copy modification.

**Patterns** — frequency array (26 / 128 slots); anagram detection; palindrome
two-pointer; expand-around-center; sliding window on strings; string reversal
variants (words, in-place); prefix function / KMP; rolling hash (Rabin–Karp);
run-length encoding; parsing and tokenizing.

### Day 3 · Hashing → `Chapter_03_Hashing`
**`Hashing.cpp`** — build a hash table from scratch: buckets + chaining, then
open addressing; hash function, load factor, rehashing. Then the STL:
`unordered_map`/`unordered_set` vs `map`/`set` (hash vs red-black tree, O(1)
average vs O(log n), unordered vs sorted); custom hash for `pair`; the
`operator[]` trap (it *inserts* on a missing key) vs `.at()` / `.find()` /
`.count()`.

**Patterns** — frequency counting; seen-set for duplicate detection; complement
lookup (two-sum shape); **prefix sum + hashmap** (subarray sum equals K — the
highest-yield combo in interviews); grouping by computed key (anagram groups);
value→index mapping; sliding window with a map; map + list for LRU.

---

## 🟠 TIER 2 — STRUCTURAL (Days 4–7)

### Day 4 · Linked List → `Chapter_04_Linked_List`
**`LinkedList.cpp`** — `Node` struct; singly linked list class (insert at
head/tail/position, delete, search, size, print, reverse); doubly linked;
circular; memory management (`new`/`delete`, leaks, dangling pointers); the
**dummy head node** technique and why it deletes half your edge cases.

**Patterns** — fast & slow pointers (Floyd's cycle detection, find middle);
reversal (iterative + recursive); merge two sorted lists; dummy node; one-pass
nth-from-end; partition; reorder; intersection of two lists; merge sort on a
list.

### Day 5 · Stacks → `Chapter_05_Stacks`
**`Stacks.cpp`** — array-backed stack class; linked-list-backed stack class;
STL `stack` (an adapter over `deque` — know what that means); `push`/`pop`/
`top`/`empty`/`size`; overflow and underflow handling.

**Patterns** — balanced parentheses; **monotonic stack** (next greater / next
smaller element — the big one); expression evaluation (infix → postfix,
postfix eval); min-stack with an auxiliary stack; stack to simulate recursion
(iterative traversals); largest rectangle in a histogram; undo / backtracking.

### Day 6 · Queues & Deque → `Chapter_06_Queues`
**`Queues.cpp`** — array-based **circular queue** (the wrap-around modulo
arithmetic, and how you distinguish full from empty); linked-list queue; STL
`queue` and `deque`; O(1) operations at both ends.

**Patterns** — the BFS skeleton; **sliding window maximum** (monotonic deque);
queue from two stacks / stack from two queues; level-order traversal;
multi-source BFS (rotting oranges shape); circular buffer / streaming windows.

### Day 7 · Heap / Priority Queue → `Chapter_07_Heap`
**`Heap.cpp`** — binary heap from scratch on a `vector`: parent/child index
math, `heapifyUp`, `heapifyDown`, `push`, `pop`, `peek`, and `buildHeap` in
O(n) (know why it's O(n), not O(n log n)); min-heap vs max-heap; STL
`priority_queue` with a custom comparator (and the `greater<>` inversion that
confuses everyone); heapsort.

**Patterns** — top-K elements (and why a size-K heap beats a full sort); K-th
largest/smallest; merge K sorted lists; **two heaps** for a running median;
greedy scheduling with a heap; heap + hashmap (task scheduler).

---

## 🟢 TIER 3 — TREES (Days 8–10)

> Prerequisite: get comfortable with recursion before Day 8 — the call stack,
> base case vs recursive case, and what the function returns *up* the tree.
> Every tree pattern is a recursion pattern wearing a costume.

### Day 8 · Binary Tree → `Chapter_08_Binary_Tree`
**`BinaryTree.cpp`** — `TreeNode` struct; build a tree; all traversals:
preorder / inorder / postorder recursively, then **iteratively with a stack**;
level-order (BFS with a queue); height, depth, node count; build from an array.

**Patterns** — the DFS recursion template (where you do the work: pre / in /
post changes everything); the BFS level template; **bottom-up vs top-down**
recursion; return-value vs reference-parameter accumulation; root-to-leaf paths
and path sum; lowest common ancestor; diameter; serialize/deserialize;
construct from two traversals; views (left / right / top / bottom).

### Day 9 · Binary Search Tree → `Chapter_09_BST`
**`BST.cpp`** — the BST invariant; insert; search; **delete (all three cases —
leaf, one child, two children via inorder successor)**; min/max; validate;
why inorder yields sorted order; degeneration into a linked list and what
balancing (AVL / red-black) fixes — note that STL `set`/`map` *are* red-black
trees.

**Patterns** — search/insert/delete; inorder for sorted output; K-th smallest;
validate with `(min, max)` range bounds — *not* by checking parents only;
floor and ceiling; range queries; build balanced BST from a sorted array;
inorder successor/predecessor; convert to a doubly linked list.

### Day 10 · Trie → `Chapter_10_Trie`
**`Trie.cpp`** — `TrieNode` (`children[26]` array vs `unordered_map` — the
memory/flexibility trade-off), `isEndOfWord` flag; insert; search;
`startsWith`; delete; count words with a given prefix.

**Patterns** — prefix matching / autocomplete; trie + backtracking for word
search on a board; longest common prefix; word break; replace words;
**binary trie for maximum XOR**; wildcard / `.` matching.

---

## 🔵 TIER 4 — ADVANCED (Days 11–12)

### Day 11 · Graphs → `Chapter_11_Graphs`
**`Graphs.cpp`** — representations: adjacency list (`vector<vector<int>>`),
adjacency matrix, edge list, and when each wins; directed vs undirected;
weighted; building from an edge list; BFS and DFS as the two core operations;
connected components; `visited` handling (and where people forget it).

**Patterns** — BFS for shortest path in an unweighted graph; multi-source BFS;
DFS recursive + iterative; **cycle detection** (directed via colors/recursion
stack, undirected via parent tracking — they are *not* the same algorithm);
topological sort (Kahn's BFS + DFS ordering); bipartite check; **grid as a
graph** (flood fill, number of islands); Dijkstra.

### Day 12 · Union-Find (DSU) → `Chapter_12_Union_Find`
**`UnionFind.cpp`** — parent array; `find` with **path compression**; `union`
by rank/size; `connected`; component count; why the amortized cost is
effectively O(1) (inverse Ackermann).

**Patterns** — connected components; cycle detection in an undirected graph;
Kruskal's MST; dynamic island counting; accounts merge; redundant connection;
DSU augmented with size or weight.

---

## ⏭️ What comes after — the 4-week sprint (Chapter_01+)

Chapter_00 teaches the **structure and the pattern**. Chapter_01 and above
**drill them on real problems**. Target: interview ready in 4 weeks.

| Week | Tier | Topics |
| :-: | :-- | :-- |
| 1 | Core | Arrays; strings; hashing; two pointers; sliding window; prefix sum; binary search |
| 2 | Structural | Linked lists; stacks; queues; monotonic stack; intervals; sorting; heap / priority queue |
| 3 | Trees | Binary trees; BST; DFS; BFS; tree recursion; tree construction; trie |
| 4 | Advanced | Graphs; graph BFS/DFS; topological sort; union find; backtracking; dynamic programming; greedy |

Already started at the repo root: `Chapter_01_Two_Pointer_Approach`,
`Chapter_02_Sliding_window`, `Chapter_03_Intervals`.

---

## 📝 Notes

- ~~`Chapter_02_Stacks/` is misnumbered~~ — renamed to `Chapter_02_Strings`.
  Stacks is Day 5 → `Chapter_05_Stacks`.
- Backtracking, DP and greedy are **techniques, not data structures** — they
  live in the Chapter_01+ sprint, not here.
- Sorting is covered where it's load-bearing (heap on Day 7, plus the STL
  `sort` toolkit on Day 1) rather than as its own day.
