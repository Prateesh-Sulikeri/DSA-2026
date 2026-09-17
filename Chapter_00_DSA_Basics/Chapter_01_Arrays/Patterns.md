# 🔵 Arrays — Patterns

> **This is the revision sheet.** Read it before writing `Patterns.cpp`, and re-read it alone before an interview.

Every pattern below follows the same template:

| Field | What it gives you |
| :-- | :-- |
| **Trigger** | How you recognise it from the problem statement |
| **Don't use when** | Where it's the wrong tool |
| **Core idea** | The mechanism, in one paragraph |
| **Invariant** | What is always true — this is what you state out loud in an interview, and what you debug against when it breaks |
| **Complexity** | Time / space |
| **Variations** | How the same idea bends into different problems |
| **Mistakes** | The bugs that actually happen |
| **Problems** | Where to drill it |

## Index

1. [Prefix Sum](#1-prefix-sum)
2. [Kadane's Algorithm](#2-kadanes-algorithm)
3. [Two Pointers (Opposite Ends)](#3-two-pointers-opposite-ends)
4. [Fast / Slow Write Pointer](#4-fast--slow-write-pointer-in-place-compaction)
5. [Fixed-Size Sliding Window](#5-fixed-size-sliding-window)
6. [Variable-Size Sliding Window](#6-variable-size-sliding-window)
7. [Binary Search](#7-binary-search)
8. [Dutch National Flag](#8-dutch-national-flag-3-way-partition)
9. [Rotation by Reversal](#9-rotation-by-reversal)
10. [Cyclic Sort / Index-as-Hash](#10-cyclic-sort--index-as-hash)
11. [XOR Tricks](#11-xor-tricks)

---

## 🧭 How to pick a pattern

**Read the constraints, not the story.** The problem statement almost always tells you which one:

| The statement says… | Reach for |
| :-- | :-- |
| "sum between index i and j", many queries | **Prefix Sum** |
| "maximum subarray sum", contiguous, no size given | **Kadane** |
| sorted input + find a pair/triplet | **Two Pointers** |
| "in place", "return the new length", O(1) space | **Write Pointer** |
| "subarray of size exactly k" | **Fixed Window** |
| "longest/shortest subarray such that `<condition>`" | **Variable Window** |
| sorted input, or "minimise the maximum" | **Binary Search** |
| exactly three categories, one pass | **Dutch National Flag** |
| "rotate by k", O(1) space | **Reversal** |
| values in range `1..n`, O(n) time **and** O(1) space | **Cyclic Sort** |
| "every element twice except one", O(1) space | **XOR** |

**Two constraint tells that override everything else:**

- **"O(1) extra space"** kills your hashmap. Look at Write Pointer, Cyclic Sort, XOR, or Two Pointers.
- **"O(n) time"** on a sorted-looking problem usually means Two Pointers or a Window, not a nested loop.

---

## 1. Prefix Sum

**Trigger**
- Repeated range-sum queries on a static array
- "Sum of the subarray from i to j"
- Counting subarrays whose sum equals K (prefix sum + hashmap)
- Equilibrium / pivot index problems
- Running totals, cumulative anything

**Don't use when**
- The array is mutated between queries → you'd rebuild O(n) every update. That's a Fenwick (BIT) or segment tree problem.
- There's only a single query → just loop once, don't build the table.

**Core idea**

Precompute cumulative sums once, then every range query is a subtraction.

```
prefix[0]   = 0
prefix[i+1] = prefix[i] + nums[i]

sum(l..r) inclusive = prefix[r+1] - prefix[l]
```

Size the prefix array `n+1`, **not** `n`. That leading zero is what lets `l = 0` work without a special case — worth the one extra slot.

**Invariant**

`prefix[i]` is always the sum of `nums[0 .. i-1]`. Nothing else.

**Complexity** — build O(n) time / O(n) space · query **O(1)**

**Variations**
- **2D prefix sum** — sum of a rectangle via inclusion-exclusion:
  ```
  region = P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1]
  ```
  Draw it once — the double-subtracted corner has to come back.
- **Suffix sum** — same idea from the right. Prefix + suffix together solve "product/sum of everything except self" in O(n) with no division.
- **Prefix product** — watch for zeros, they poison everything downstream.
- **Prefix XOR** — `rangeXor(l..r) = pre[r+1] ^ pre[l]`. Same algebra, because XOR is its own inverse just like subtraction undoes addition.
- **Difference array** — the inverse tool. Range *update* in O(1), then one O(n) pass to reconstruct. Use when updates are many and reads come last.
- **Prefix sum + hashmap** — count subarrays summing to K. Store how many times each prefix value has occurred; at index `i`, look up `(prefix - K)`. **This is the high-yield one.** It generalises to "divisible by K" (store `prefix % K`) and "equal number of 0s and 1s" (map `0 → -1`).

**Mistakes**
- Sizing the array `n` instead of `n+1`, then fighting off-by-ones forever.
- Using `prefix[r]` instead of `prefix[r+1]` for an inclusive range.
- **Integer overflow.** Sums grow fast — use `long long`.
- Rebuilding the prefix array inside the query loop. Defeats the entire pattern and turns O(1) queries back into O(n).
- For the hashmap variant: forgetting to seed the map with `{0 → 1}` before the loop, which drops every subarray that starts at index 0.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 303 | Range Sum Query - Immutable | |
| 304 | Range Sum Query 2D - Immutable | |
| 560 | Subarray Sum Equals K | ⭐ learn cold |
| 724 | Find Pivot Index | |
| 238 | Product of Array Except Self | prefix + suffix |
| 525 | Contiguous Array | |
| 1109 | Corporate Flight Bookings | difference array |

---

## 2. Kadane's Algorithm

**Trigger**
- "Maximum sum of a contiguous subarray"
- Best contiguous run, no size constraint given
- Max profit from one buy/sell (it's Kadane on the diff array)

**Don't use when**
- The subarray must have a fixed size → Fixed Sliding Window.
- Elements don't need to be contiguous → just sum the positives.
- You need the max **product** → related but different; you must also track the running minimum, because one negative flips min into max.

**Core idea**

Walk the array once. At every element there is exactly one decision: extend the subarray that ends at the previous element, or throw it away and start fresh here.

```cpp
current = max(nums[i], current + nums[i]);
best    = max(best, current);
```

The moment the running sum goes negative it can only hurt whatever comes next, so you drop it. That's the whole algorithm.

**Invariant**

- `current` = the maximum sum of a subarray **ending exactly at index i**
- `best` = the maximum over all subarrays ending at any index seen so far

Keeping these two separate is the entire trick — people who merge them get wrong answers.

**Complexity** — O(n) time, O(1) space

**Variations**
- **Track the indices** — record a tentative start when you restart, and commit start/end whenever `best` updates.
- **Minimum subarray sum** — same code with min/max swapped.
- **Maximum Product Subarray** — carry *both* the running max and running min, and swap them when `nums[i]` is negative.
- **Circular array** — the answer is either a normal Kadane result, or `total - (minimum subarray sum)`. Special-case all-negative input, because the "wrap" answer would otherwise be an empty subarray.
- **Max sum with at most one deletion** — two DP states: with and without a deletion used.
- **2D maximum sum rectangle** — fix a pair of columns, compress the rows into a 1D array, run Kadane. O(cols² × rows).

**Mistakes**
- **Initialising `best` and `current` to 0.** On an all-negative array that returns 0, which is not a valid non-empty subarray. Initialise both to `nums[0]` and start the loop at `i = 1`.
- Initialising with `nums[0]` and then *still* starting the loop at `i = 0`, which double-counts the first element.
- Updating `best` only inside the "extend" branch. It must update every iteration, unconditionally.

**Problems**

| # | Problem |
| :-- | :-- |
| 53 | Maximum Subarray |
| 152 | Maximum Product Subarray |
| 121 | Best Time to Buy and Sell Stock |
| 918 | Maximum Sum Circular Subarray |
| 1749 | Maximum Absolute Sum of Any Subarray |

---

## 3. Two Pointers (Opposite Ends)

**Trigger**
- Input is sorted (or you're allowed to sort it) and you need a pair, triplet or quadruplet with some sum property
- Palindrome checking
- Area / container problems bounded by two walls
- Reversing or merging in place
- Any "start from both ends and walk inward"

**Don't use when**
- The array is unsorted **and** the problem needs original indices — sorting destroys them. Use a hashmap instead (classic Two Sum).
- You genuinely need every pair → that's O(n²), no way around it.

**Core idea**

`left = 0`, `right = n-1`. Compare, then move the **one** pointer that could possibly improve the answer, and shrink until they meet. Each move must provably discard only non-answers — that proof is what makes it correct, and it's what an interviewer will ask you for.

Two Sum on sorted input is the cleanest example:

```
sum too small -> the only way to grow it is left++   (right-- shrinks it)
sum too big   -> right--
```

Because the array is sorted, each move eliminates a whole row/column of the pair space. That's how O(n²) collapses to O(n).

**Invariant**

The answer, if one exists, always lies within the window `[left, right]`. You never move a pointer past a candidate you haven't ruled out.

**Complexity** — O(n) for the scan; O(n log n) overall if you had to sort first. O(1) extra space.

**Variations**
- **Two Sum on sorted input** — the base case.
- **3Sum** — sort, fix index `i`, two-pointer the remaining suffix. O(n²). **4Sum** — fix two, two-pointer the rest. O(n³).
- **Container With Most Water** — area is limited by the *shorter* wall, so move the shorter one. Moving the taller one can never increase the area: width shrinks and height is still capped by the short wall.
- **Trapping Rain Water** — carry `leftMax` and `rightMax`; the smaller side is the one whose water level is already determined, so process it.
- **Valid Palindrome** — walk inward, skipping non-alphanumerics.
- **Merge Sorted Array in place** — fill from the **back** so you never overwrite data you haven't read yet.
- **Squares of a Sorted Array** — the largest square is at one end or the other, so fill the output back-to-front.

**Mistakes**
- `while (left < right)` vs `<=`. For pair-finding you want strictly `<`, or you'll pair an element with itself.
- **Moving the wrong pointer.** In Container With Most Water, moving the taller wall is the classic wrong move.
- Forgetting to skip duplicates in 3Sum/4Sum → duplicate triplets in the output. You must skip on the fixed index **and** after a successful match.
- Sorting when the problem asks for original indices.

**Problems**

| # | Problem |
| :-- | :-- |
| 167 | Two Sum II - Input Array Is Sorted |
| 15 | 3Sum |
| 18 | 4Sum |
| 11 | Container With Most Water |
| 42 | Trapping Rain Water |
| 125 | Valid Palindrome |
| 88 | Merge Sorted Array |
| 977 | Squares of a Sorted Array |

---

## 4. Fast / Slow Write Pointer (In-Place Compaction)

**Trigger**
- "Do it in place"
- "Return the new length" / "the rest of the array doesn't matter"
- "Use O(1) extra space"
- Removing, filtering, or compacting while preserving relative order

**Don't use when**
- You must keep the removed elements.
- Relative order is irrelevant **and** swapping to the end is cheaper.

**Core idea**

Two pointers moving the same direction at different speeds:

- `read` scans every element, skipping nothing
- `write` marks the slot where the next **kept** element belongs

When the keep-condition holds, copy `nums[read]` into `nums[write]` and advance `write`. At the end, `write` **is** the new logical length.

Notice that `write` never overtakes `read`, so you can never clobber an element you haven't already examined. That's why in-place is safe here.

**Invariant**

`nums[0 .. write-1]` is the finished, correct answer so far. `write <= read`, always.

**Complexity** — O(n) time, O(1) space, single pass

**Variations**
- **Remove by value** — keep when `nums[read] != val`.
- **Remove duplicates from a sorted array** — keep when `write == 0 || nums[read] != nums[write-1]`.
- **Allow at most K duplicates** — compare against `nums[write-K]` instead. One character changes and the problem generalises. Understand why.
- **Move Zeroes** — write all non-zeros, then fill the tail with zeros. (Or swap instead of copy and skip the second pass.)
- **Partition by any predicate** — the condition is a parameter.
- **Dutch National Flag** (Pattern 8) is the three-category cousin of this.

**Mistakes**
- Returning `write - 1`. The new length is `write`.
- Using `nums[write-1]` without guarding `write == 0` → reads index `-1`.
- Forgetting the second pass when the problem requires the tail be zeroed (Move Zeroes explicitly demands it).
- Incrementing `write` on every iteration instead of only on a keep.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 27 | Remove Element | |
| 26 | Remove Duplicates from Sorted Array | |
| 80 | Remove Duplicates from Sorted Array II | the `nums[write-k]` trick |
| 283 | Move Zeroes | |
| 905 | Sort Array By Parity | |

---

## 5. Fixed-Size Sliding Window

**Trigger**
- The size `k` is given in the problem: "subarray of size k", "k consecutive days", "window of k elements"
- Max / min / average / sum over every window of length `k`

**Don't use when**
- The window size is determined by a condition rather than given → Variable-Size Window (Pattern 6).

**Core idea**

Build the first window explicitly. Then slide one step at a time: add the element entering on the right, subtract the element leaving on the left.

```cpp
windowSum += nums[i] - nums[i - k];
```

**Never recompute the window from scratch.** That single line is what turns O(n·k) into O(n), and it's the whole pattern.

**Invariant**

After processing index `i` (for `i >= k-1`), the window is exactly `[i-k+1 .. i]` and your accumulator describes precisely that range.

**Complexity** — O(n) time; O(1) space for sums, O(k) if carrying a map or deque

**Variations**
- **Maximum / minimum sum of size k** — the base case.
- **Maximum average** — same thing, divide at the end (don't divide inside the loop, you lose precision and time).
- **Window with a frequency map** — max sum of *distinct* elements of size k, count of anagrams, permutation-in-string. The map tracks the window's contents; erase keys when their count hits zero.
- **"Max points from k cards taken from either end"** — reframe it. Taking k from the ends = leaving a contiguous window of size `n-k` in the middle. Minimise the middle window. **The reframing is the lesson here.**
- **Sliding Window Maximum** — needs a monotonic deque to get O(n). That's a Day 6 structure, but the window skeleton is identical.
- **First negative number in every window.**

**Mistakes**
- Recomputing the sum inside the loop — silently O(n·k).
- **Off-by-one on the outgoing index.** It is `nums[i-k]`, not `i-k-1` or `i-k+1`. Derive it once: when the window ends at `i`, it starts at `i-k+1`, so the element that just left is at `i-k`.
- Starting the slide loop at `i = k-1` instead of `i = k`, re-adding an element already in the window.
- Not guarding `n < k`.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 643 | Maximum Average Subarray I | |
| 1423 | Maximum Points You Can Obtain From Cards | |
| 2461 | Maximum Sum of Distinct Subarrays With Length K | |
| 438 | Find All Anagrams in a String | |
| 567 | Permutation in String | |
| 239 | Sliding Window Maximum | revisit after Day 6 (deque) |

---

## 6. Variable-Size Sliding Window

**Trigger**
- "Longest subarray such that `<condition>`"
- "Shortest/minimum subarray such that `<condition>`"
- "At most K distinct", "no repeating characters", "sum >= target"
- The size is **not** given — the condition decides it

**Don't use when**
- The condition isn't monotonic in the window size. Shrinking must actually help restore validity, and growing must actually push toward violation. If neither holds, the window doesn't apply.
- Negative numbers with a "sum >= target" condition — growing no longer monotonically increases the sum. That becomes prefix sum + deque/map.

**Core idea**

Right expands, always, one element per iteration. Left only moves when the window is invalid. Because each pointer only ever moves forward, the total work is O(n) even though the code looks like a nested loop — each element enters the window once and leaves at most once.

**Two shapes, and knowing which you're in is everything:**

| Shape | Procedure |
| :-- | :-- |
| **Longest** | expand right; **while invalid**, shrink left; record the answer *after* the window is valid again |
| **Shortest** | expand right; **while valid**, record the answer *then* shrink left |

Note the difference: for "longest" you record when valid; for "shortest" you record while valid and keep shrinking to try to do better.

**Invariant**

For the "longest" shape: at the bottom of each iteration the window `[left..right]` is valid, and you have already considered every valid window ending at `right`.

**Complexity** — O(n) amortized time, O(k) space for the auxiliary map/set

**Variations**
- **Longest substring without repeating characters** — set, or a last-seen index map that lets you jump `left` directly instead of shrinking one at a time.
- **Longest with at most K distinct** — map of counts, shrink while `map.size() > K`.
- **Fruit Into Baskets** — literally "at most 2 distinct". Same code, `K=2`.
- **Longest Repeating Character Replacement** — valid when `windowLength - maxFrequency <= k`. The subtle part is that `maxFrequency` never needs to be decreased — think about why the answer stays correct.
- **Minimum Size Subarray Sum** — the "shortest" shape.
- **Minimum Window Substring** — need-map plus a `formed` counter so validity is an O(1) check instead of an O(k) scan. The hardest common one.
- **Exactly K distinct** = `atMost(K) - atMost(K-1)`. **Memorise this reduction**; "exactly" is almost never solved directly.

**Mistakes**
- Using `if` instead of `while` for the shrink step. One shrink may not be enough to restore validity.
- **Recording the answer in the wrong place** — the single most common bug in this pattern. Decide which shape you're in first.
- When shrinking, forgetting to decrement the count in the map, or leaving zero-count keys behind so that `map.size()` reports too many distinct elements. Erase the key when its count hits zero.
- Assuming the nested loop makes it O(n²). It doesn't — but be ready to explain the amortized argument.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 3 | Longest Substring Without Repeating Characters | |
| 209 | Minimum Size Subarray Sum | |
| 424 | Longest Repeating Character Replacement | |
| 904 | Fruit Into Baskets | |
| 76 | Minimum Window Substring | 🥊 the boss fight |
| 992 | Subarrays with K Different Integers | the `atMost(K)-atMost(K-1)` trick |
| 1004 | Max Consecutive Ones III | |

---

## 7. Binary Search

**Trigger**
- Sorted array, find something
- O(log n) is demanded, or `n` is huge (1e9) so O(n) is impossible
- A **monotonic predicate** exists: the answer space looks like `false, false, false, true, true, true` — find the boundary
- **"Minimise the maximum X"** or **"maximise the minimum X"** ← the giveaway phrasing for binary search on the answer

**Don't use when**
- Unsorted input with no monotonic property to exploit.

**Core idea**

Maintain a search space and throw away half of it every step. The array version is the easy half of this pattern. The important half is **binary search on the answer**: when you can't search the input, search the *range of possible answers*, using a feasibility check as the comparator.

"Can we finish with eating speed `s`?" is monotonic — if speed `s` works, every speed above it works. So binary search `s` over `[1, max(piles)]` and ask the feasibility question at each midpoint. **Recognising that the answer space is monotonic is the skill; the search itself is boilerplate.**

**Invariant**

The answer, if it exists, is always inside `[low, high]`. Every discard must be provably safe.

**Complexity** — O(log n), or O(n log(range)) when each feasibility check costs O(n)

**Variations**
- **Exact match** — the textbook version.
- **`lower_bound`** — first index with value `>=` target. **`upper_bound`** — first index with value `>` target. Count of a value = `upper_bound - lower_bound`.
- **First / last occurrence** of a duplicated value.
- **Search in a rotated sorted array** — at any `mid`, one half is guaranteed sorted. Work out which, then decide whether the target lies in it.
- **Find minimum in a rotated sorted array** — find the inflection point.
- **Find a peak element** — works on *unsorted* input, because "is there a larger neighbour" is the monotonic signal.
- **Binary search on the answer** — Koko Eating Bananas, Ship Capacity, Split Array Largest Sum, Minimum Days to Make Bouquets, Median of Two Sorted Arrays (partition-based — the hardest one).
- **2D matrix search** — treat the `m×n` matrix as a flat sorted array and map `index → (index / cols, index % cols)`.

**Mistakes**
- **`mid = (low + high) / 2` overflows** when both are near `INT_MAX`. Always write `mid = low + (high - low) / 2`.
- Mismatching the loop condition with the update rule:
  ```
  while (low <= high)  pairs with  low = mid + 1 / high = mid - 1
  while (low <  high)  pairs with  low = mid + 1 / high = mid
  ```
  Mix them and you get an infinite loop or an off-by-one.
- Writing `low = mid` (without `+1`) with an integer-floor `mid` → infinite loop when `high = low + 1`.
- **Improvising a new template for every boundary problem.** Pick *one* `lower_bound`-style template, understand it completely, and reuse it.
- Forgetting the input must actually be sorted.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 704 | Binary Search | |
| 35 | Search Insert Position | |
| 34 | Find First and Last Position of Element in Sorted Array | |
| 33 | Search in Rotated Sorted Array | |
| 153 | Find Minimum in Rotated Sorted Array | |
| 162 | Find Peak Element | |
| 875 | Koko Eating Bananas | ⭐ search on the answer |
| 410 | Split Array Largest Sum | |
| 4 | Median of Two Sorted Arrays | |

---

## 8. Dutch National Flag (3-Way Partition)

**Trigger**
- Exactly three categories to group in a single pass
- "Sort an array of 0s, 1s and 2s"
- Partitioning around a pivot when duplicates of the pivot exist
- One pass **and** O(1) space demanded

**Don't use when**
- More than three categories → counting sort.
- Stability is required — this pattern is **not** stable, it swaps freely.

**Core idea**

Three pointers carve the array into four regions. Everything before `low` is settled as 0, the span `[low, mid)` is settled as 1, everything after `high` is settled as 2, and `[mid, high]` is the shrinking unknown region. You're done when the unknown region is empty.

```cpp
nums[mid] == 0 -> swap(nums[low], nums[mid]); low++; mid++;
nums[mid] == 1 -> mid++;
nums[mid] == 2 -> swap(nums[mid], nums[high]); high--;   // mid stays!
```

**Invariant**

```
nums[0      .. low-1 ] == 0
nums[low    .. mid-1 ] == 1
nums[mid    .. high  ] == UNEXAMINED
nums[high+1 .. n-1   ] == 2
```

**Complexity** — O(n) time, O(1) space, one pass

### ⚠️ The one question that matters

**Why does `mid` advance after swapping with `low`, but *not* after swapping with `high`?**

- Swapping with `low` brings back a value from the 1s region, which you have **already examined** and know is a 1. Safe to move past it.
- Swapping with `high` brings back a value from the **unexamined** region. You have no idea what it is, so you must examine it next iteration.

If you can explain that cleanly, you understand this pattern.

**Variations**
- **Quicksort's 3-way partition** — the same routine, and it's what makes quicksort survive arrays full of duplicate keys.
- **Two-category partition** (evens/odds, negatives/positives) — simpler, one write pointer; that's Pattern 4.
- **Wiggle Sort II** uses a 3-way partition around the median.

**Mistakes**
- **Advancing `mid` after the high-swap.** This is *the* bug in this pattern.
- Loop condition must be `while (mid <= high)`, not `mid < high`, or you leave the final unknown element unprocessed.
- Using a two-pass counting sort when the interviewer asked for one pass. Counting sort is a perfectly good answer — just say it first, then offer this as the one-pass improvement.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 75 | Sort Colors | ⭐ the canonical one |
| 215 | Kth Largest Element | quickselect partition |
| 324 | Wiggle Sort II | |

---

## 9. Rotation by Reversal

**Trigger**
- "Rotate the array by k positions"
- Cyclic shift, left or right
- O(1) extra space demanded (otherwise a copy is trivially easier)

**Core idea**

Three reversals, no extra array:

1. Reverse the whole array
2. Reverse the first `k` elements
3. Reverse the remaining `n-k` elements

Step 1 gets every element roughly where it belongs but backwards within each block; steps 2 and 3 undo the backwardness block by block.

**Invariant**

Reversal is its own inverse. Reversing a block and then reversing it again restores the original order, so the composition of the three reversals lands each element exactly `k` positions over.

**Complexity** — O(n) time, O(1) space

(The trivial copy-to-a-new-array is also O(n) time but O(n) space — mention both, then give this one.)

**Variations**
- **Rotate left by k == rotate right by n-k.** Convert and reuse one routine.
- **Juggling / cyclic replacement** — move elements along their cycles, using `gcd(n,k)` to know how many cycles exist. Also O(1) space, but far more error-prone under interview pressure. Know it exists; lead with reversal.
- **Rotate a string** — identical.
- **Rotate an image / matrix 90°** — transpose, then reverse each row. Same "compose two simple ops" flavour, worth internalising together.
- **Check if one string is a rotation of another** — `s2` is a rotation of `s1` iff `s2` is a substring of `s1 + s1`.

**Mistakes**
- **Forgetting `k %= n`.** If `k > n` you'll reverse past the end of the array.
- Modulo by zero when `n == 0`. Guard the empty array.
- Negative `k`, if the problem allows it: normalise with `((k % n) + n) % n`.
- Mixing up left and right rotation. State which one you're doing before you write a line.

**Problems**

| # | Problem |
| :-- | :-- |
| 189 | Rotate Array |
| 48 | Rotate Image |
| 796 | Rotate String |

---

## 10. Cyclic Sort / Index-as-Hash

**Trigger**
- The array holds numbers in a known bounded range: `1..n` or `0..n-1`
- "Find the missing number" / "the duplicate" / "all numbers that disappeared" / "the first missing positive"
- O(n) time **and** O(1) space demanded — which explicitly rules out the hashmap you were about to reach for

**Don't use when**
- Values aren't bounded by the array length — the whole trick depends on "value `v` has a home index".
- You must not modify the input (both techniques below mutate it).

**Core idea**

When values are in the range `1..n`, the array's own **indices are a perfect hash table** — value `v` belongs at index `v-1`. No extra space needed, because the storage you need is already sitting there.

**(a) Cyclic sort** — put each value at its home index:

```cpp
for each i:
    while nums[i] is in range && nums[i] != nums[correctIndex]:
        swap(nums[i], nums[correctIndex]);
```

Then one scan: the first index where `nums[i] != i+1` is your answer.

**(b) Sign marking** — mark presence without extra space:

Visit value `v`, then negate `nums[abs(v)-1]` to record "v was seen". Afterwards, any index still holding a positive value was never marked, so `index+1` is missing. Use `abs()` when reading, since the value may already have been flipped.

**Invariant** (cyclic sort)

After index `i` is processed, either `nums[i]` is at its correct home or the value is out of range and will never find one.

**Complexity** — O(n) time, O(1) space

> The `while` loop inside the `for` loop **looks** like O(n²) but is not: every swap places at least one value permanently at its home, and there are only `n` homes. So there are at most `n` swaps in total. **Be ready to say this out loud** — interviewers ask.

**Variations**
- **Missing Number** (`0..n`, one missing) — also solvable by XOR or by the Gauss formula `n(n+1)/2 - actualSum`.
- **Find All Numbers Disappeared** — sign marking, then collect the positive indices.
- **Find the Duplicate Number** — or treat the array as a linked list and use Floyd's cycle detection, which has the advantage of not mutating the input at all.
- **Find All Duplicates** — sign marking; a value already negative means you've seen it before.
- **First Missing Positive** — the hard one. Cyclic sort ignoring everything outside `1..n`, then scan for the first mismatch.
- **Set Mismatch** — find the duplicated and the missing value together.

**Mistakes**
- Using `if` instead of `while` for the swap — one swap may drop another value that also needs relocating.
- **Getting the home index wrong.** For values `1..n` the home of `v` is index `v-1`. For values `0..n-1` the home is index `v`. Decide which range you're in before writing anything.
- Looping on `nums[i] != i+1` instead of `nums[i] != nums[correctIndex]`. With duplicates present, the first form spins forever.
- Sign marking breaks if the array can contain `0` (negating 0 does nothing) — and it destroys the input, so restore it if the caller still needs the data.
- The Gauss-sum shortcut can overflow for large `n`. XOR cannot.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 268 | Missing Number | |
| 448 | Find All Numbers Disappeared in an Array | |
| 287 | Find the Duplicate Number | |
| 442 | Find All Duplicates in an Array | |
| 41 | First Missing Positive | 🔥 hard, and worth it |
| 645 | Set Mismatch | |

---

## 11. XOR Tricks

**Trigger**
- "Every element appears twice except for one"
- Find the single / the two unique numbers
- O(1) space demanded on a problem that's begging for a hashmap
- Swap two values without a temporary

**Core properties** — everything below follows from these three:

```
a ^ a = 0          a value cancels itself
a ^ 0 = a          zero is the identity
commutative + associative
                   -> order doesn't matter, so pairs cancel no matter
                      where they sit in the array
```

**Core idea**

XOR the whole array together. Every value that appears an even number of times annihilates itself, and only the odd one out survives. There's no cleverness to remember — it's just the algebra above.

**Complexity** — O(n) time, O(1) space

**Variations**
- **Single Number** — XOR everything. One line.
- **Single Number III** (exactly two uniques) — XOR everything to get `x^y`. That result is non-zero, so it has at least one set bit — and any set bit is a position where `x` and `y` **differ**. Isolate the lowest set bit with `(diff & -diff)`, use it to split the array into two groups, and XOR each group separately. Elegant, and a genuine interview favourite.
- **Single Number II** (others appear 3 times) — XOR does **not** work here, because triples don't cancel. Count set bits at each of the 32 positions and take the count mod 3. (Or the `ones`/`twos` bitmask state machine, if you want to show off.)
- **Missing Number** — XOR all indices with all values; everything present cancels and the missing one survives.
- **Prefix XOR array** — `rangeXor(l..r) = pre[r+1] ^ pre[l]`, exactly like prefix sums, because XOR is its own inverse.
- **Maximum XOR of two numbers** — needs a binary trie. That's Day 10 — note the connection when you get there.

**Mistakes**
- Reaching for XOR when elements appear **three** times. It silently gives a wrong answer.
- Forgetting to initialise the accumulator to `0`.
- Not knowing what `(diff & -diff)` does. It isolates the **lowest set bit**, and it relies on two's-complement negation. If you can't explain it, don't use it in an interview — use `(diff & ~(diff - 1))` or just find a set bit with a loop.

**Problems**

| # | Problem | |
| :-- | :-- | :-- |
| 136 | Single Number | |
| 137 | Single Number II | |
| 260 | Single Number III | |
| 268 | Missing Number | |
| 421 | Maximum XOR of Two Numbers in an Array | revisit after Trie |

---

## 🔗 Cross-cutting notes

### Patterns that combine

| Combination | Solves |
| :-- | :-- |
| **Prefix Sum + HashMap** | Counting subarrays with a target sum — the single most productive combination on this whole sheet |
| **Sort + Two Pointers** | Every kSum problem |
| **Binary Search + greedy feasibility check** | "Minimise the maximum" |
| **Sliding Window + HashMap** | Every "distinct elements in a window" |

### What the constraints are telling you

| `n` | What fits |
| :-- | :-- |
| ≤ 20 | Exponential is fine — backtracking, bitmask |
| ≤ 100–500 | O(n³) fine |
| ≤ 5,000 | O(n²) fine |
| 1e5 – 1e6 | You need O(n log n) or O(n) |
| ≥ 1e9 | O(log n) — binary search on the answer, or math |

### Before you code, say this out loud

1. **What's the invariant?**
2. **What are the edge cases** — empty array, single element, all identical, all negative, `k > n`?
3. **What's the complexity**, and does it fit the constraints?

> Stating the invariant first is the difference between a candidate who debugs their way to an answer and one who reasons their way to it.
