# 📋 DSA-2026 Quick Reference Cheat Sheet

---

## 🔴 PART 1: TWO POINTERS APPROACH

### When to Use
- ✅ Sorted/sortable arrays
- ✅ Find pairs/triplets with specific properties
- ✅ Reverse operations
- ✅ Partition problems
- ✅ In-place modifications

### Template 1: Opposite Ends
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) {
        // Process
        left++;
    } else {
        right--;
    }
}
```

**Problems**: Container With Most Water, Valid Palindrome II, Boats to Save People

---

### Template 2: Sort + Two Pointers (Finding Pairs)
```cpp
sort(arr.begin(), arr.end());
for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue; // Skip duplicates
    int left = i + 1, right = n - 1;
    while (left < right) {
        int sum = arr[i] + arr[left] + arr[right];
        if (sum == target) {
            // Found triplet
            left++;
            right--;
            while (left < right && arr[left] == arr[left-1]) left++;
            while (left < right && arr[right] == arr[right+1]) right--;
        }
        else if (sum < target) left++;
        else right--;
    }
}
```

**Problems**: Two Sum (with sorted array), Three Sum, Four Sum, Triangle Nums

---

### Template 3: In-Place Modifications
```cpp
int k = 0; // Position to fill
for (int i = 0; i < n; i++) {
    if (condition) {
        arr[k++] = arr[i];
    }
}
```

**Problems**: Move Zeros, Remove Duplicates from Sorted Array II

---

### Template 4: Dutch National Flag (3-Way Partition)
```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (arr[mid] == 0) {
        swap(arr[low++], arr[mid++]);
    }
    else if (arr[mid] == 1) {
        mid++;
    }
    else { // arr[mid] == 2
        swap(arr[mid], arr[high--]);
    }
}
```

**Problems**: Sort Colors

---

### Template 5: Two Pointers with Precomputation
```cpp
vector<int> leftMax(n), rightMax(n);

// Build prefix/suffix arrays
for (int i = 0; i < n; i++) {
    leftMax[i] = max(leftMax[i-1], arr[i]);
}

for (int i = n-1; i >= 0; i--) {
    rightMax[i] = max(rightMax[i+1], arr[i]);
}

// Use both arrays
for (int i = 0; i < n; i++) {
    result[i] = function(leftMax[i], rightMax[i]);
}
```

**Problems**: Trapping Rain Water

---

### ⭐ Key Patterns

| Problem | Trick |
|---------|-------|
| **Two Sum** | HashMap or sort + two pointers |
| **Three Sum** | Sort + fix one element + two pointers |
| **Container Water** | Greedy: move inward from max width |
| **Trapping Rain** | Min(leftMax, rightMax) - height |
| **Sort Colors** | Dutch flag 3-way partition |
| **Move Zeros** | Swap technique maintains relative order |
| **Duplicates** | Skip duplicate check before inner loop |

---

## 🟢 PART 2: SLIDING WINDOW

### When to Use
- ✅ Subarray/substring problems
- ✅ Contiguous sequences
- ✅ "First", "Minimum", "Maximum" substring/subarray
- ✅ Fixed or variable window

### Template 1: Fixed Window Size
```cpp
int windowSum = 0;
for (int i = 0; i < k; i++) {
    windowSum += arr[i];
}
int maxSum = windowSum;

for (int i = k; i < n; i++) {
    windowSum = windowSum - arr[i-k] + arr[i];
    maxSum = max(maxSum, windowSum);
}
```

**Problems**: Max Sum of sub-array size k, Max Points from Cards

---

### Template 2: Variable Window (Expand-Contract)
```cpp
int left = 0, right = 0;
unordered_map<char, int> freq;

while (right < n) {
    // Expand
    freq[s[right]]++;
    right++;
    
    // Contract if condition not met
    while (/* condition */) {
        freq[s[left]]--;
        if (freq[s[left]] == 0) freq.erase(s[left]);
        left++;
    }
    
    // Update result
    result = max(result, right - left);
}
```

**Problems**: Longest Substring Without Repeating Characters, Fruit Into Basket, Minimum Window Substring

---

### Template 3: Distinct Elements Window
```cpp
int left = 0;
unordered_map<int, int> count;

for (int right = 0; right < n; right++) {
    count[arr[right]]++;
    
    while (count.size() > k) {
        count[arr[left]]--;
        if (count[arr[left]] == 0) count.erase(arr[left]);
        left++;
    }
    
    if (count.size() == k && right - left + 1 == k) {
        result += sum(arr[left...right]);
    }
}
```

**Problems**: Max Sum of Distinct sub-array length k, Fruit Into Basket

---

### Template 4: Character Replacement Window
```cpp
int left = 0;
unordered_map<char, int> freq;
int maxFreq = 0;

for (int right = 0; right < n; right++) {
    freq[s[right]]++;
    maxFreq = max(maxFreq, freq[s[right]]);
    
    // Window size - max frequency = characters to replace
    while (right - left + 1 - maxFreq > k) {
        freq[s[left]]--;
        left++;
    }
    
    result = max(result, right - left + 1);
}
```

**Problems**: Longest Repeating Character Replacement

---

### Template 5: Minimum Window Pattern
```cpp
unordered_map<char, int> target, window;
int left = 0, formed = 0, required = target.size();
int minLen = INT_MAX, minLeft = 0;

for (int right = 0; right < n; right++) {
    char c = s[right];
    window[c]++;
    
    if (target.count(c) && window[c] == target[c]) {
        formed++;
    }
    
    while (formed == required) {
        if (right - left + 1 < minLen) {
            minLen = right - left + 1;
            minLeft = left;
        }
        
        char c = s[left];
        window[c]--;
        if (target.count(c) && window[c] < target[c]) {
            formed--;
        }
        left++;
    }
}
```

**Problems**: Minimum Window Substring (⭐ VERY IMPORTANT)

---

### ⭐ Key Patterns

| Problem | Technique |
|---------|-----------|
| **Fixed Window** | Subtract left element when adding right |
| **Longest Substring** | Track character frequency, expand-contract |
| **Fruit Basket** | At most 2 distinct → use hashmap size |
| **Character Replace** | Replace = windowSize - maxFrequency |
| **Minimum Window** | 2-pointer + formed/required counters |
| **Optimization** | Prefix sums for max sum problems |

---

## 🔵 PART 3: INTERVALS

### When to Use
- ✅ Overlapping/merging ranges
- ✅ Scheduling problems
- ✅ Time conflicts
- ✅ Insertion into existing intervals

### Template 1: Merge Intervals
```cpp
sort(intervals.begin(), intervals.end());
vector<vector<int>> merged;

for (auto& interval : intervals) {
    if (merged.empty() || merged.back()[1] < interval[0]) {
        // No overlap
        merged.push_back(interval);
    } else {
        // Overlap - merge
        merged.back()[1] = max(merged.back()[1], interval[1]);
    }
}
```

**Problems**: Merge Intervals, Employee Free Time

---

### Template 2: Insert Interval
```cpp
vector<vector<int>> result;
int i = 0;
auto [start, end] = newInterval;

// Add all intervals ending before newInterval
while (i < intervals.size() && intervals[i][1] < start) {
    result.push_back(intervals[i++]);
}

// Merge overlapping intervals
while (i < intervals.size() && intervals[i][0] <= end) {
    start = min(start, intervals[i][0]);
    end = max(end, intervals[i][1]);
    i++;
}
result.push_back({start, end});

// Add remaining intervals
while (i < intervals.size()) {
    result.push_back(intervals[i++]);
}
```

**Problems**: Insert Intervals

---

### Template 3: Non-Overlapping Intervals (Greedy)
```cpp
sort(intervals.begin(), intervals.end(), 
     [](const vector<int>& a, const vector<int>& b) {
         return a[1] < b[1]; // Sort by END time!
     });

int count = 0, prevEnd = INT_MIN;
for (auto& interval : intervals) {
    if (interval[0] >= prevEnd) {
        // No overlap with previous
        count++;
        prevEnd = interval[1];
    }
}
// Result = total - count
```

**Problems**: Non-Overlapping Intervals

---

### Template 4: Meeting Rooms (Sorting)
```cpp
sort(meetings.begin(), meetings.end());

for (int i = 1; i < meetings.size(); i++) {
    if (meetings[i][0] < meetings[i-1][1]) {
        return false; // Overlap found
    }
}
return true;
```

**Problems**: Meeting Rooms

---

### ⭐ Key Patterns

| Problem | Trick |
|---------|-------|
| **Merge** | Sort + compare `merged.back()[1]` with current `[0]` |
| **Insert** | 3 phases: before, merge overlapping, after |
| **Non-Overlapping** | Greedy: sort by END time, pick earliest ender |
| **Meeting Rooms** | Check if any `intervals[i][0] < intervals[i-1][1]` |
| **Overlap Condition** | `a[0] <= b[1] && b[0] <= a[1]` OR simpler: `a[0] < b[1] && b[0] < a[1]` |

---

## 🟡 QUICK COMPLEXITY REFERENCE

### Time Complexity

| Pattern | Average | Best | Worst |
|---------|---------|------|-------|
| Two Pointers | O(n) | O(n) | O(n log n)* |
| Sliding Window | O(n) | O(n) | O(n) |
| Intervals | O(n log n) | O(n log n) | O(n log n) |

*with sorting

### Space Complexity

| Pattern | Space |
|---------|-------|
| Two Pointers | O(1)† |
| Sliding Window | O(k) or O(unique) |
| Intervals | O(n) or O(1)† |

†excluding output

---

## 🎯 COMMON PITFALLS & FIXES

### Two Pointers
```cpp
❌ while (left <= right)  // Can access same element twice
✅ while (left < right)

❌ Skip duplicates after processing
✅ Skip duplicates BEFORE inner logic (for 3-sum)

❌ Forgetting to update maxFreq in Dutch flag
✅ After each operation, recalculate state
```

### Sliding Window
```cpp
❌ Not resetting hashmap/counter properly
✅ Use hashmap.erase() when count becomes 0

❌ Expanding then contracting in wrong order
✅ Expand first, then check condition, then contract

❌ Assuming left < right always
✅ Use left <= right for fixed windows
```

### Intervals
```cpp
❌ Sorting by start only (doesn't work for insert)
✅ Insert uses 3-phase approach, not just sort

❌ Overlap condition: a[1] <= b[0]
✅ Overlap condition: a[1] >= b[0]  (or a[0] <= b[1] && b[0] <= a[1])

❌ Non-overlapping: sort by start time
✅ Non-overlapping: MUST sort by END time (greedy)
```

---

## 🚀 PROBLEM SELECTION DECISION TREE

```
Is it a subarray/substring problem?
├─ YES → Can window size be determined?
│   ├─ YES (fixed) → Fixed Sliding Window
│   └─ NO (dynamic) → Variable Window (expand-contract)
└─ NO → Is it about ordering/pairing?
    └─ YES → Can we use two pointers?
        ├─ YES → Sort first, then 2-pointers
        └─ NO → Is it about intervals?
            └─ YES → Merge/Insert/Overlap problem
                └─ Sort by appropriate time → Solve
```

---

## 📚 MUST-KNOW TECHNIQUES

### 1️⃣ Precomputation (Prefix/Suffix)
```cpp
// Trapping Rain Water, Container Water
vector<int> leftMax(n), rightMax(n);
for (int i = 1; i < n; i++) leftMax[i] = max(leftMax[i-1], arr[i]);
for (int i = n-2; i >= 0; i--) rightMax[i] = max(rightMax[i+1], arr[i]);
```

### 2️⃣ In-Place Modification
```cpp
// Move Zeros, Remove Duplicates
int k = 0;
for (int i = 0; i < n; i++) {
    if (condition) arr[k++] = arr[i];
}
```

### 3️⃣ Duplicate Skipping
```cpp
// Three Sum, Four Sum
if (i > start && arr[i] == arr[i-1]) continue;
while (left < right && arr[left] == arr[left-1]) left++;
while (left < right && arr[right] == arr[right+1]) right--;
```

### 4️⃣ Greedy Selection
```cpp
// Boats, Assign Cookies, Non-overlapping Intervals
sort(...); // By relevant metric
for (...) {
    if (condition_satisfied) pick_greedily();
}
```

### 5️⃣ HashMap for Frequency
```cpp
// Sliding Window problems
unordered_map<char, int> freq;
freq[char]++;
if (freq[char] == target[char]) formed++;
```

---

## 💪 STUDY CHECKLIST

### Before Interview
- [ ] Memorize all 5 two-pointer templates
- [ ] Know when to use hashmap vs. array for frequency
- [ ] Practice merge vs. insert intervals distinction
- [ ] Know sorting orders (start, end, custom comparator)
- [ ] Understand overlap conditions thoroughly
- [ ] Practice 1-2 problems from each pattern

### Red Flags During Problem
- [ ] Sorting without reason → think carefully
- [ ] HashMap blowup → consider fixed window
- [ ] Manual pointer movement → use templates
- [ ] Forgetting edge cases → think about boundaries

---

## 🔗 PROBLEM LINKAGE

```
Two Pointers (Sorted Array)
├─ Two Sum → Container → Three Sum → Four Sum → Triangle
├─ Move Zeros → Remove Duplicates → Valid Palindrome
├─ Sort Colors (Dutch Flag) → Partition problem family
└─ Trapping Rain (Precomputation) → Water problems

Sliding Window (Contiguous)
├─ Fixed Window → Max Points Cards
├─ Variable Window → Substring → Fruit Basket
├─ Distinct Elements → Max Sum Distinct
├─ Character Replacement → Repeating Char
└─ Minimum Window → ALL techniques combined ⭐

Intervals (Sorting)
├─ Meeting Rooms → Sorting intro
├─ Merge → Core operation
├─ Insert → Extension of merge
├─ Non-Overlapping → Greedy variant
└─ Employee Free Time → Complex merge
```

---

## ⚡ FINAL TIPS

1. **Always sort first** (unless specifically prohibited by time constraint)
2. **Use hashmap for frequency**, array for indices
3. **Two-pointer**: Opposite ends, moving inward
4. **Sliding window**: Expand until condition breaks, then contract
5. **Intervals**: 3-phase approach (before, merge, after)
6. **Greedy**: Works when locally optimal = globally optimal
7. **Edge cases**: Empty input, single element, all same, all different
8. **Time limit**: O(n log n) sorting is usually fine for n ≤ 10^5

---

**Happy Coding! 🎯**