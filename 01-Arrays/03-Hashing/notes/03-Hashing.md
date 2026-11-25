---
tags: [dsa, pattern/arrays-hashing, pattern/arrays-hashing/hashing]
status: learning
last_revised: 2026-11-25
---

# Hashing

## TL;DR
- **What:** store what you've seen in a HashSet (presence) or HashMap (count / index / group), so every later lookup is O(1).
- **When:** the problem asks "have I seen this before?", "how many times?", or "which items belong together?".
- **Complexity:** O(n) time · O(n) space.

**Rule:** if the brute force compares every pair, trade O(n) memory for O(1) lookups with a HashSet or HashMap.

## Recognition Signals
- "Contains duplicate" / "any value appears twice" → HashSet, return on the first failed `add`
- "Count how often each value appears" → HashMap value → count (or `int[26]` for lowercase letters)
- "Value appearing more than n/2 times" → frequency map, return as soon as a count passes `n / 2` (O(1) space → Boyer-Moore)
- "Unsorted array, find two indices with sum = target" → HashMap value → index, look up `target − x` before you put `x`
- "Same letters, rearranged" / "is t an anagram of s" → compare letter counts, `++` for one string and `--` for the other
- "Group items that are the same in some way" → HashMap key → list, where the key is the shared form (anagrams → sorted word or letter-count string)
- "No repeats in any row, column or box" (Sudoku) → one seen-set per group, box index `(r / 3) * 3 + c / 3`
- "Longest run of consecutive values", unsorted, O(n) → HashSet, only count up from `x` when `x − 1` is missing
- "Top k most frequent" / "k most common" → count map, then bucket by frequency (O(n)) or a size-k min-heap (O(n log k))
- ✗ Not this when: O(1) extra space is required and the array can be modified → sort, then compare neighbours
- ✗ Not this when: the input is already sorted → [[02-Two-Pointers]] or compare neighbours, no extra memory needed

## Template
```java
// Seen-set: stop at the first repeat
Set<Integer> seen = new HashSet<>();
for (int num : nums) {
    if (!seen.add(num)) return true;   // add() returns false when num is already in the set
}
return false;
```

```java
// Frequency map
Map<Integer, Integer> count = new HashMap<>();
for (int num : nums) {
    count.merge(num, 1, Integer::sum);  // count[num]++
}
```

## Variants
| Variant | Structure | Use when |
|---------|-----------|----------|
| **Seen-set** | `HashSet<T>` | only presence matters (duplicates, membership) |
| **Frequency map** | `HashMap<T, Integer>` | you need how many times each value appears |
| **Fixed-size count array** | `int[26]` / `int[128]` | the keys are small, known characters → faster than a map |
| **Group by key** | `HashMap<K, List<T>>` + `computeIfAbsent` | items that share a canonical form go in one bucket |
| **Bucket by frequency** | `HashMap` counts + `List<Integer>[n + 1]` | top k by count → frequencies are at most n, so bucket instead of sorting |
| **One set per group** | `Set<T>[]` (or `boolean[groups][values]`) | the same "no repeats" rule applies to many groups at once (Sudoku rows, columns, boxes) |
| **Run start check** | `HashSet<T>` + `contains(x − 1)` | count consecutive runs in O(n) → only walk from the first value of each run |
| **Sort instead** | none (sort in place) | O(1) extra space and the input may be changed → O(n log n) |

## Problems

### LC 217 · Contains Duplicate · 🟢 Easy
[Link](https://leetcode.com/problems/contains-duplicate/) · Confidence: ✅

- **Key insight:** a HashSet answers "have I seen this value?" in O(1), so one pass finds a repeat. `set.add(x)` returns `false` the moment `x` is already there.
- **Approach:**
  1. Create an empty `HashSet<Integer>`.
  2. For each number, call `seen.add(num)`.
  3. If `add` returns `false` → the number was already seen → return `true`.
  4. Loop ends with no repeat → return `false`.
- **Brute → Optimal:** O(n²) compare every pair → O(n log n) sort + compare neighbours, O(1) extra space → O(n) one pass with a HashSet.
- **Complexity:** O(n) time · O(n) space
- **Edge cases:** single element, all values the same, all values distinct, the repeat is the last element, negatives, `Integer.MIN_VALUE` / `MAX_VALUE`.
- **Clarifying questions:** how big can the array be (is O(n) memory fine)? Can I modify the input (sorting allowed)? Return just true/false, or the duplicate value?
- **Follow-ups:** O(1) extra space → sort and compare neighbours · duplicate within distance k (LC 219) → HashMap value → last index, or a sliding window set of size k · values in range `1..n` with one repeat (LC 287) → Floyd's cycle detection.
- **Practice:** `01-Arrays/03-Hashing/code/ContainsDuplicate.java` · run: `java ContainsDuplicate.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public boolean containsDuplicate(int[] nums) {
>         Set<Integer> seen = new HashSet<>();
>         for (int num : nums) {
>             if (!seen.add(num)) return true;   // false → already in the set
>         }
>         return false;
>     }
> }
> ```

### LC 242 · Valid Anagram · 🟢 Easy
[Link](https://leetcode.com/problems/valid-anagram/) · Confidence: ✅

- **Key insight:** two strings are anagrams exactly when every letter appears the same number of times in both. Count up for `s`, count down for `t` in one `int[26]`; if every slot ends at 0, they match.
- **Approach:**
  1. If the lengths differ → return `false` straight away.
  2. Make `int[26] count`.
  3. For each index `i`: `count[s[i] − 'a']++` and `count[t[i] − 'a']--`.
  4. If any slot is not 0 → `false`, otherwise `true`.
- **Brute → Optimal:** O(n log n) sort both and compare → O(n) count letters in an `int[26]`, O(1) space.
- **Complexity:** count array O(n) time · O(1) space (26 slots, whatever the length) · sort O(n log n) time · O(n) space (two `char[]` copies)
- **Edge cases:** different lengths, same letters with different counts (`"aab"` vs `"abb"`), identical strings, single character, one letter repeated.
- **Clarifying questions:** only lowercase `a–z`, or Unicode / uppercase? Do spaces and punctuation count? Can the strings be empty?
- **Follow-ups:** Unicode input → `HashMap<Character, Integer>` instead of `int[26]` (or `int[128]` for ASCII) · group many words into anagram sets (LC 49) → HashMap with the sorted word (or the count array) as the key · find every anagram of `p` inside `s` (LC 438) → sliding window of the same counts.
- **Practice:** `01-Arrays/03-Hashing/code/ValidAnagram.java` · run: `java ValidAnagram.java` from that folder (or F5 in Zed)

> [!example]- Code (Java) · Approach 1: sort both, compare
> ```java
> class Solution {
>     public boolean isAnagram(String s, String t) {
>         if (s.length() != t.length()) return false;
>
>         char[] sArr = s.toCharArray();
>         char[] tArr = t.toCharArray();
>
>         Arrays.sort(sArr);                 // anagrams become the same string once sorted
>         Arrays.sort(tArr);
>
>         return Arrays.equals(sArr, tArr);
>     }
> }
> ```

> [!example]- Code (Java) · Approach 2: count array (optimal)
> ```java
> class Solution {
>     public boolean isAnagram(String s, String t) {
>         if (s.length() != t.length()) return false;
>         int[] count = new int[26];
>         for (int i = 0; i < s.length(); i++) {
>             count[s.charAt(i) - 'a']++;    // letter in s → +1
>             count[t.charAt(i) - 'a']--;    // letter in t → −1
>         }
>         for (int c : count) {
>             if (c != 0) return false;      // some letter is unbalanced
>         }
>         return true;
>     }
> }
> ```

### LC 1 · Two Sum (HashMap) · 🟢 Easy
[Link](https://leetcode.com/problems/two-sum/) · Confidence: ✅

- **Key insight:** for each number, the partner you need is `target − nums[i]`. Keep a HashMap of value → index for everything seen so far, and look the partner up in O(1).
- **Approach:**
  1. Walk the array once with index `i`.
  2. If `target − nums[i]` is already in the map → return `{map.get(...), i}`.
  3. Otherwise put `nums[i] → i` in the map. Check **before** putting, so one element is never used twice.
- **Brute → Optimal:** O(n²) [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy|every pair]] → O(n log n) [[02-Two-Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]], sorting shuffles the indices → O(n) one pass with a HashMap (this one).
- **Complexity:** O(n) time · O(n) space
- **Edge cases:** the same value twice (`[3,3]`, target 6), negatives, the pair at the very end, an element that is exactly half of the target but appears once.
- **Clarifying questions:** is there always exactly one answer? Return indices or values? Can I use the same element twice? Can values be negative?
- **Follow-ups:** the array is sorted (LC 167) → two pointers, O(1) space · return all pairs / unique pairs → sort + two pointers, skip duplicates · data stream (LC 170) → keep a count map, check on `find`.
- **Practice:** `01-Arrays/03-Hashing/code/TwoSumHashMap.java` · run: `java TwoSumHashMap.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] twoSum(int[] nums, int target) {
>         Map<Integer, Integer> seen = new HashMap<>();   // value → index
>         for (int i = 0; i < nums.length; i++) {
>             Integer j = seen.get(target - nums[i]);
>             if (j != null) return new int[]{j, i};
>             seen.put(nums[i], i);                       // put AFTER the lookup: never pairs i with itself
>         }
>         return new int[]{-1, -1};
>     }
> }
> ```

### LC 169 · Majority Element (HashMap) · 🟢 Easy
[Link](https://leetcode.com/problems/majority-element/) · Confidence: ✅

- **Key insight:** count each value in a HashMap as you go; the first value whose count passes `n / 2` is the majority, so return it right there.
- **Approach:**
  1. Walk the array once, `freq = map.getOrDefault(num, 0) + 1`, then put it back.
  2. If `freq > n / 2` → return `num` (early exit, no second pass).
  3. Loop ends → no majority (can't happen when one is guaranteed).
- **Brute → Optimal:** O(n²) count each element → O(n) HashMap counts, O(n) space (this one) → O(n) [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy|Boyer-Moore]], O(1) space.
- **Complexity:** frequency map O(n) time · O(n) space (up to n/2 distinct keys) · Boyer-Moore O(n) time · O(1) space
- **Edge cases:** single element, all the same, majority at the very end (`[1,2,2]`), negatives.
- **Clarifying questions:** is a majority guaranteed to exist? Is O(n) extra memory fine, or is O(1) required? Can I sort the array?
- **Follow-ups:** O(1) space → [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy|Boyer-Moore voting]] · no guarantee → return a sentinel when the loop finishes · elements > n/3 times (LC 229) → same map, collect every key with count > n/3 (or Boyer-Moore with 2 candidates).
- **Practice:** `01-Arrays/03-Hashing/code/MajorityElementHashMap.java` · run: `java MajorityElementHashMap.java` from that folder (or F5 in Zed) · `majorityElement` = map, `majElem` = Boyer-Moore

> [!example]- Code (Java) · Approach 1: frequency map
> ```java
> class Solution {
>     public int majorityElement(int[] nums) {
>         Map<Integer, Integer> freqMap = new HashMap<>();
>         for (int n : nums) {
>             int freq = freqMap.getOrDefault(n, 0) + 1;
>             freqMap.put(n, freq);
>             if (freq > nums.length / 2) return n;   // strictly more than half → majority, stop early
>         }
>         return -1;   // unreachable when a majority is guaranteed
>     }
> }
> ```

> [!example]- Code (Java) · Approach 2: Boyer-Moore voting (O(1) space)
> ```java
> class Solution {
>     public int majorityElement(int[] nums) {
>         int candidate = 0, count = 0;
>         for (int num : nums) {
>             if (count == 0) candidate = num;          // no live candidate → take this one
>             count += (num == candidate) ? 1 : -1;     // same → vote for, different → cancel one
>         }
>         return candidate;   // guaranteed to exist, so no verify pass
>     }
> }
> ```

### LC 49 · Group Anagrams · 🟡 Medium
[Link](https://leetcode.com/problems/group-anagrams/) · Confidence: ✅

- **Key insight:** anagrams share one canonical form (the word with its letters sorted), so use that form as a HashMap key and drop every word into its key's list.
- **Approach:**
  1. For each word, sort its letters → `key` (`"eat"` → `"aet"`).
  2. `map.computeIfAbsent(key, k -> new ArrayList<>()).add(word)` → creates the list the first time, then appends.
  3. Return `new ArrayList<>(map.values())`.
- **Brute → Optimal:** O(n² · k) compare every pair with [[03-Hashing#LC 242 · Valid Anagram · 🟢 Easy|Valid Anagram]] → O(n · k log k) sorted-word key → O(n · k) count-array key (no sort).
- **Complexity:** sorted key O(n · k log k) time · O(n · k) space · count key O(n · k) time · O(n · k) space (n words, k = longest word)
- **Edge cases:** empty string `""` (its own group), a single word, no anagrams at all (every group size 1), all words anagrams of each other, duplicate words.
- **Clarifying questions:** only lowercase `a–z`? Does the order of groups or of words inside a group matter? Can a word be empty?
- **Follow-ups:** Unicode input → sorted-word key still works, the `int[26]` key doesn't · very long words → count key, O(k) instead of O(k log k) · find anagrams of one pattern inside a string (LC 438) → sliding window of letter counts.
- **Practice:** `01-Arrays/03-Hashing/code/GroupAnagrams.java` · run: `java GroupAnagrams.java` from that folder (or F5 in Zed) · `groupAnagrams` = sorted key, `grpAnagrams` = count key

> [!example]- Code (Java) · Approach 1: sorted word as the key
> ```java
> class Solution {
>     public List<List<String>> groupAnagrams(String[] strs) {
>         Map<String, List<String>> groups = new HashMap<>();
>         for (String word : strs) {
>             char[] letters = word.toCharArray();
>             Arrays.sort(letters);
>             String key = new String(letters);                          // "eat", "tea" → "aet"
>             groups.computeIfAbsent(key, k -> new ArrayList<>()).add(word);   // make the list once, then append
>         }
>         return new ArrayList<>(groups.values());
>     }
> }
> ```

> [!example]- Code (Java) · Approach 2: letter counts as the key (no sort)
> ```java
> class Solution {
>     public List<List<String>> groupAnagrams(String[] strs) {
>         Map<List<Integer>, List<String>> groups = new HashMap<>();
>         for (String word : strs) {
>             int[] count = new int[26];
>             for (char c : word.toCharArray()) count[c - 'a']++;
>             List<Integer> key = Arrays.stream(count).boxed().toList();   // List compares by value, int[] doesn't
>             groups.computeIfAbsent(key, k -> new ArrayList<>()).add(word);
>         }
>         return new ArrayList<>(groups.values());
>     }
> }
> ```

### LC 347 · Top K Frequent Elements · 🟡 Medium
[Link](https://leetcode.com/problems/top-k-frequent-elements/) · Confidence: ✅

- **Key insight:** a frequency can never be more than `n`, so after counting with a HashMap, put each value in bucket `freq` (an array of lists of size `n + 1`) and read the buckets from the highest frequency down. That's a bucket sort, so it takes O(n) with no full sort.
- **Approach:**
  1. Count every value: `count.merge(num, 1, Integer::sum)`.
  2. Make `List<Integer>[] buckets = new List[n + 1]`, then for each (value, freq) add the value to `buckets[freq]`.
  3. Walk `freq` from `n` down to `1`, copying values into the result until it holds `k`.
- **Brute → Optimal:** O(n log n) count, then sort the distinct values by frequency → O(n log k) min-heap of size k (drop the least frequent once size > k) → O(n) bucket by frequency.
- **Complexity:** bucket O(n) time · O(n) space · heap O(n log k) time · O(n + k) space
- **Edge cases:** `k` = number of distinct values (return them all), a single element, all values the same, negatives and 0 as the answer, one value much more frequent than the rest.
- **Clarifying questions:** is the answer guaranteed to be unique (no tie at the k-th place)? Does the output order matter? Is `k` always ≤ the number of distinct values?
- **Follow-ups:** better than O(n log n) → bucket sort O(n) or heap O(n log k) · stream of numbers / `k` much smaller than n → keep a size-k min-heap · ties must break by value → heap with a comparator on (freq, value) · top k frequent words (LC 692) → same idea, ties broken alphabetically.
- **Practice:** `01-Arrays/03-Hashing/code/TopKFrequentElements.java` · run: `java TopKFrequentElements.java` from that folder (or F5 in Zed)

> [!example]- Code (Java) · Approach 1: min-heap of size k
> ```java
> class Solution {
>     public int[] topKFrequent(int[] nums, int k) {
>         Map<Integer, Integer> count = new HashMap<>();
>         for (int num : nums) count.merge(num, 1, Integer::sum);
>
>         // min-heap by frequency → the root is the least frequent of the current top k
>         PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> count.get(a) - count.get(b));
>         for (int num : count.keySet()) {
>             minHeap.offer(num);
>             if (minHeap.size() > k) minHeap.poll();   // drop the least frequent, keep k
>         }
>
>         int[] result = new int[k];
>         for (int i = k - 1; i >= 0; i--) result[i] = minHeap.poll();
>         return result;
>     }
> }
> ```

> [!example]- Code (Java) · Approach 2: bucket by frequency (optimal)
> ```java
> class Solution {
>     public int[] topKFrequent(int[] nums, int k) {
>         Map<Integer, Integer> count = new HashMap<>();
>         for (int num : nums) count.merge(num, 1, Integer::sum);
>
>         List<Integer>[] buckets = new List[nums.length + 1];   // index = frequency, max is n
>         for (Map.Entry<Integer, Integer> e : count.entrySet()) {
>             int freq = e.getValue();
>             if (buckets[freq] == null) buckets[freq] = new ArrayList<>();
>             buckets[freq].add(e.getKey());
>         }
>
>         int[] result = new int[k];
>         int filled = 0;
>         for (int freq = nums.length; freq >= 1 && filled < k; freq--) {   // highest frequency first
>             if (buckets[freq] == null) continue;
>             for (int num : buckets[freq]) {
>                 if (filled == k) break;
>                 result[filled++] = num;
>             }
>         }
>         return result;
>     }
> }
> ```

### LC 36 · Valid Sudoku · 🟡 Medium
[Link](https://leetcode.com/problems/valid-sudoku/) · Confidence: ✅

- **Key insight:** each of the 9 rows, 9 columns and 9 boxes needs its own seen-set. Cell `(r, c)` belongs to box `(r / 3) * 3 + c / 3`, so one pass over the board checks all 27 sets.
- **Approach:**
  1. Make three arrays of 9 `HashSet<Character>`: `rows`, `cols`, `boxes`.
  2. For every cell: skip `'.'`. Otherwise `box = (r / 3) * 3 + c / 3`.
  3. If `add` fails on `rows[r]`, `cols[c]` or `boxes[box]` → the digit is repeated → return `false`.
  4. Whole board scanned with no repeat → return `true`.
- **Brute → Optimal:** three separate passes (rows, then columns, then boxes), each with a fresh set → one pass with 27 sets. Both are O(81) = O(1), so the one-pass version just has less code.
- **Complexity:** O(1) time · O(1) space (the board is always 9 × 9; for an n × n board it is O(n²) time · O(n²) space)
- **Edge cases:** an empty board (valid), a digit repeated only inside a box (not in its row or column), the bottom-right box, a board that is valid but can't be solved (still valid).
- **Clarifying questions:** do I check only the filled cells, or must the board be solvable? Is the board always 9 × 9? Only digits `'1'`–`'9'` and `'.'`?
- **Follow-ups:** no sets → `boolean[9][9]` per group, indexed by `digit − '1'` (or a 9-bit mask per group, `seen & (1 << d)`) · a single set → add strings like `"5 in row 0"`, `"5 in col 3"`, `"5 in box 1"` · actually solve it (LC 37) → backtracking with these same checks.
- **Practice:** `01-Arrays/03-Hashing/code/ValidSudoku.java` · run: `java ValidSudoku.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public boolean isValidSudoku(char[][] board) {
>         Set<Character>[] rows = new HashSet[9], cols = new HashSet[9], boxes = new HashSet[9];
>         for (int i = 0; i < 9; i++) {
>             rows[i] = new HashSet<>();
>             cols[i] = new HashSet<>();
>             boxes[i] = new HashSet<>();
>         }
>         for (int r = 0; r < 9; r++) {
>             for (int c = 0; c < 9; c++) {
>                 char digit = board[r][c];
>                 if (digit == '.') continue;
>                 int box = (r / 3) * 3 + c / 3;              // 0..8, left to right, top to bottom
>                 if (!rows[r].add(digit) || !cols[c].add(digit) || !boxes[box].add(digit)) return false;
>             }
>         }
>         return true;
>     }
> }
> ```

### LC 128 · Longest Consecutive Sequence · 🟡 Medium
[Link](https://leetcode.com/problems/longest-consecutive-sequence/) · Confidence: ✅

- **Key insight:** put every number in a HashSet, then only start counting from a number `x` whose `x − 1` is NOT in the set (the start of a run). Every number is walked over at most once, so the whole thing is O(n) without sorting.
- **Approach:**
  1. Add every number to a `HashSet<Integer>` (this also drops duplicates).
  2. Loop over the **set**: if `num − 1` is in the set → `num` is not a start → skip it.
  3. Otherwise count up: `while (set.contains(num + length)) length++`.
  4. `longest = max(longest, length)`, then return `longest`.
- **Brute → Optimal:** O(n²) (or worse) count up from every number with no start check → O(n log n) sort and count neighbour runs (skip equal values) → O(n) HashSet, count only from starts.
- **Complexity:** O(n) time · O(n) space
- **Edge cases:** empty array (0), single element, duplicates (`[1,0,1,2]` → 3), all the same value, no two values consecutive, negatives crossing 0.
- **Clarifying questions:** can the array be empty? Are there duplicates, and do they count toward the length? What is the value range (could `x + 1` overflow)? Is O(n) extra memory fine?
- **Follow-ups:** O(1) extra space → sort, then count runs (skip equal neighbours) · return the sequence itself → keep the best start, output `start .. start + longest − 1` · numbers arrive one by one → HashMap of run end → run length, merge the left and right runs on insert (or Union-Find, 18).
- **Practice:** `01-Arrays/03-Hashing/code/LongestConsecutiveSequence.java` · run: `java LongestConsecutiveSequence.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int longestConsecutive(int[] nums) {
>         Set<Integer> set = new HashSet<>();
>         for (int num : nums) set.add(num);
>
>         int longest = 0;
>         for (int num : set) {                          // loop the set, not nums → duplicates don't redo the work
>             if (set.contains(num - 1)) continue;       // not a start → its run gets counted from the start
>             int length = 1;
>             while (set.contains(num + length)) length++;
>             longest = Math.max(longest, length);
>         }
>         return longest;
>     }
> }
> ```

## Pitfalls
- Longest Consecutive: no "is `num − 1` in the set?" check → you count up from every number in a run → O(n²) on `[1..n]`.
- Longest Consecutive: looping over `nums` instead of the set → `[1,1,1,…,1,2,3,…]` re-walks the same run once per duplicate.
- Longest Consecutive: `num − 1` / `num + length` wrap around at `Integer.MIN_VALUE` / `MAX_VALUE` → `[MAX, MIN, MAX − 1]` returns 3 instead of 2. Fine for LC (±10⁹); otherwise use `long` or guard the ends.
- Calling `contains` and then `add` → two lookups for one; `add` already tells you if the value was there.
- Sorting to save memory changes the caller's array → ask before you modify the input.
- Building the whole set first and comparing `set.size() < nums.length` works, but never exits early.
- Two Sum: putting `nums[i]` in the map before the lookup → `[3, 2, 4]`, target 6 returns `[0, 0]` (the 3 pairs with itself).
- Anagram: skipping the length check → `"a"` vs `"ab"` slips through if you only loop over one string.
- Anagram: `int[26]` with `c − 'a'` breaks on uppercase or Unicode → `ArrayIndexOutOfBounds`; ask about the charset first.
- Group Anagrams: `int[]` as a map key compares by reference → every word gets its own group; convert it to a `List<Integer>` (`Arrays.stream(count).boxed().toList()`) or a `String` (`Arrays.toString`).
- Group Anagrams: building the count key by joining digits with no separator → `[1,11]` and `[11,1]` both become `"111"`.
- `get` → null check → `put` → `add` is four lines for one idea; `computeIfAbsent(key, k -> new ArrayList<>()).add(x)` does it in one.
- Top K: buckets of size `n` instead of `n + 1` → a value that fills the whole array (freq = n) is out of bounds.
- Top K: max-heap of every distinct value works but is O(n log n); a **min**-heap capped at k is O(n log k).
- Sudoku: box index `r / 3 + c / 3` → boxes 0–4 only, and different boxes share a set. Use `(r / 3) * 3 + c / 3`.
- Sudoku: adding `'.'` to the sets → two empty cells look like a repeat. Skip empty cells first.
- Majority: `freq >= n / 2` instead of `>` → `[1,2]` returns 1, but "more than half" means strictly greater.

## Related
- [[01-Linear-Scan]]: sibling Arrays sub-topic, for one pass with a running value.
- LC 1 Two Sum, the other two approaches: [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy|brute force]] (O(n²)) · [[02-Two-Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]] (O(n log n)).
- LC 169 Majority Element, O(1)-space approach: [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy|Boyer-Moore voting]].
- [[02-Two-Pointers]]: sibling Arrays sub-topic; use it instead of a set when the input is sorted.
- [[09-Heap]]: LC 347 Top K Frequent Elements also fits Heap / Top-K; the size-k min-heap approach is in its code callout.
- [[02-Sliding-Window]]: "duplicate within distance k" keeps a set of only the last k values.
