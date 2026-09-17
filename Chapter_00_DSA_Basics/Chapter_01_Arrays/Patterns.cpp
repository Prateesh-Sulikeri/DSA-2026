#include <bits/stdc++.h>
using namespace std;

/*
    ==========================================================================
    CHAPTER 00.01 : ARRAYS -- PATTERN IMPLEMENTATIONS
    ==========================================================================

    READ Patterns.md FIRST. This file is the hands-on half: you implement
    each pattern and its variations, so you feel how one idea bends into
    different problems.

    STRUCTURE -- one class per pattern:

        class PatternName {
        public:
            // the base implementation
            // then each variation as its own method
            void demo();   // runs the base + every variation, printing results
        };

    Why classes? So main() stays readable. main() should be nothing more than:

        PrefixSum().demo();
        Kadane().demo();
        ...

    Each class owns its own test data and prints its own output. If main()
    starts filling up with loose vectors and function calls, the structure
    has leaked -- push it back into the class.

    RULES FOR YOURSELF
      - Write the base case first, get it printing, THEN add variations.
      - For every method, know its invariant before you write the loop.
      - Test the edge cases listed under each pattern. They're where the
        bugs are, and they're what an interviewer probes.

    COMPILE
        g++ -std=c++17 -Wall Patterns.cpp -o patterns && ./patterns
    --------------------------------------------------------------------------
   INFO: TAG LEGEND -- the first word is what Zed highlights, the second is
         what it means. See CLAUDE.md and the global settings palette.

       TODO:              code for YOU to write                    (green)
       XXX:   THINK --    MINE: answer this before you code          (purple)
       XXX:   (bare)      YOURS: your section markers and your answers (purple)
       INFO:  PART/theory section header, or what-it-is-and-why    (blue)
       NOTE:  INVARIANT-- what must always be true                 (teal)
       WARN:  TRAP --     the classic mistake here                 (orange)
       FIXME:             review finding; needs fixing             (yellow)
       BUG:               confirmed wrong behaviour                (red)
    ==========================================================================
*/


/* --------------------------------------------------------------------------
   SHARED HELPER
   TODO: printArray(const vector<int>& arr, const string& label = "")
         Reuse the one you wrote in Arrays.cpp. Every demo() needs it.
   -------------------------------------------------------------------------- */


/* ==========================================================================
   INFO: PATTERN 1 -- class PrefixSum
   ==========================================================================
   TODO:
     vector<int> build(const vector<int>& nums)
        prefix[0] = 0, prefix[i+1] = prefix[i] + nums[i].  Size n+1.
        NOTE: INVARIANT -- prefix[i] is the sum of nums[0..i-1]. Nothing else.

     int rangeSum(const vector<int>& prefix, int l, int r)
        Inclusive both ends. One subtraction, no loop.

   VARIATIONS:
     int  pivotIndex(const vector<int>& nums)
        Index where the left sum equals the right sum. You can do this
        without building the array at all -- total and a running left sum.

     vector<int> productExceptSelf(const vector<int>& nums)
        Prefix products * suffix products. No division allowed.
        Bonus: do it with O(1) extra space (output array doesn't count).

     int  countSubarraysWithSum(const vector<int>& nums, int k)
        PREFIX SUM + HASHMAP. The highest-value method in this file.
        Seed the map with {0 -> 1} before the loop. Understand why:
        it accounts for subarrays that start at index 0.

     vector<vector<int>> build2D(const vector<vector<int>>& grid)
     int  regionSum(..., int r1, int c1, int r2, int c2)
        Inclusion-exclusion. Draw the rectangle before you write it -- the
        corner you subtract twice has to be added back.

   WARN: TRAP -- edge cases: empty array, single element, negative numbers, l == r.
   XXX: THINK -- why size n+1 and not n? What special case does prefix[0] = 0 remove?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 2 -- class Kadane
   ==========================================================================
   TODO:
     int maxSubArraySum(const vector<int>& nums)
        current = max(nums[i], current + nums[i]);  best = max(best, current);
        NOTE: INVARIANT -- current = best sum of a subarray ENDING EXACTLY at i;
                   best = best over all subarrays seen so far. Keep them separate.
        Initialise BOTH to nums[0] and start the loop at i = 1.

   VARIATIONS:
     pair<int,int> maxSubArrayIndices(const vector<int>& nums)
        Same loop, but track a tentative start (set it when you restart) and
        commit start/end whenever best updates.

     int maxProductSubArray(const vector<int>& nums)
        Carry BOTH a running max and a running min. When nums[i] < 0, swap
        them before updating -- a negative turns the smallest into the
        largest. This is the variation people fail.

     int maxCircularSubArraySum(const vector<int>& nums)
        Answer = max(normalKadane, total - minSubarraySum).
        Special-case an all-negative array, or the wrap branch returns an
        empty subarray. Work out why before you code the guard.

     int maxSubArrayWithOneDeletion(const vector<int>& nums)
        Two running states: best ending here with no deletion used, and
        best ending here with one deletion used.

   WARN: TRAP -- edge cases: ALL NEGATIVE (the classic failure), single element,
               all zeros, one positive among negatives.
   XXX: THINK -- initialise best = 0 and run it on {-3,-1,-2}. What do you get, and why
      is it wrong?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 3 -- class TwoPointers          (opposite ends)
   ==========================================================================
   TODO:
     void reverseInPlace(vector<int>& nums)
        left = 0, right = n-1, swap and walk inward.

     vector<int> twoSumSorted(const vector<int>& nums, int target)
        Move left when the sum is too small, right when too big.
        Say out loud WHY that's safe -- it's the correctness proof.

   VARIATIONS:
     vector<vector<int>> threeSum(vector<int> nums)
        Sort, fix i, two-pointer the suffix. Skip duplicates in TWO places:
        on the fixed index, and after recording a match.

     int maxArea(const vector<int>& height)
        Container With Most Water. Always move the SHORTER wall.
        XXX: THINK -- prove that moving the taller wall can never improve the answer.

     int trapRainWater(const vector<int>& height)
        Carry leftMax and rightMax. Process whichever side is smaller --
        that side's water level is already fully determined.

     bool isPalindrome(const string& s)
        Walk inward, skipping non-alphanumeric, case-insensitive.

     void mergeSortedInPlace(vector<int>& a, int m, vector<int>& b, int n)
        Fill from the BACK. Filling forward overwrites unread data.

   WARN: TRAP -- edge cases: empty, 2 elements, all identical, no valid pair.
   XXX: THINK -- while (left < right) or (left <= right)? What breaks with the wrong one?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 4 -- class WritePointer         (in-place compaction)
   ==========================================================================
   TODO:
     int removeElement(vector<int>& nums, int val)
        read scans all; write marks where the next kept element goes.
        NOTE: INVARIANT -- nums[0..write-1] is the finished answer so far; write <= read.
        Return write -- that IS the new length.

   VARIATIONS:
     int removeDuplicates(vector<int>& nums)
        Sorted input. Keep when write == 0 || nums[read] != nums[write-1].

     int removeDuplicatesAtMostK(vector<int>& nums, int k)
        Compare against nums[write - k] instead. ONE character changes and
        the problem generalises. Make sure you can explain why that works.

     void moveZeroes(vector<int>& nums)
        Write the non-zeros, then zero-fill the tail. Then rewrite it using
        swap instead and skip the second pass. Compare the two.

     int partitionByParity(vector<int>& nums)
        Same skeleton, predicate as the only difference.

   WARN: TRAP -- edge cases: empty, all elements removed, nothing removed, single element.
   XXX: THINK -- return write or write - 1? Reason it through on a 1-element array.
   XXX: THINK -- why can write never clobber an element read hasn't visited yet?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 5 -- class FixedWindow
   ==========================================================================
   TODO:
     int maxSumOfSizeK(const vector<int>& nums, int k)
        NOTE: INVARIANT -- after index i, the window is exactly [i-k+1 .. i].
        Build the first window. Then slide:
            windowSum += nums[i] - nums[i-k];
        WARN: TRAP -- never recompute the window. Start the slide loop at i = k,
              and the outgoing element is nums[i-k] -- derive it, don't guess.

   VARIATIONS:
     double maxAverageOfSizeK(const vector<int>& nums, int k)
        Divide once at the end, never inside the loop.

     long long maxSumDistinctOfSizeK(const vector<int>& nums, int k)
        Window + frequency map. Only a window with map.size() == k counts.
        Erase a key the moment its count hits zero, or size() will lie.

     int maxPointsFromCards(const vector<int>& cards, int k)
        Take k from either end. REFRAME IT: that leaves a contiguous window
        of size n-k in the middle. Minimise that window's sum. The reframing
        is the whole lesson.

     vector<int> firstNegativeInWindow(const vector<int>& nums, int k)

   WARN: TRAP -- edge cases: n < k, k == 1, k == n, all negatives.
   XXX: THINK -- the outgoing element is nums[i-k]. Derive it -- don't memorise it.
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 6 -- class VariableWindow
   ==========================================================================
   INFO: two shapes. Knowing which one you're in is the whole pattern.
   NOTE: INVARIANT (longest shape) -- at the bottom of each iteration the window is
   valid, and every valid window ending at right has been considered.
   Know which one you're writing BEFORE you start:
       LONGEST : expand right; while invalid, shrink left; record when valid.
       SHORTEST: expand right; while valid, record THEN shrink left.

   TODO:
     int longestUniqueSubarray(const vector<int>& nums)
        Longest run with no repeats. Set, or a last-seen index map.

     int minSubarrayLenWithSum(const vector<int>& nums, int target)
        The SHORTEST shape. Note where you record the answer, and how that
        differs from the method above.

   VARIATIONS:
     int longestWithAtMostKDistinct(const vector<int>& nums, int k)
        Count map; shrink while map.size() > k.

     int totalFruit(const vector<int>& fruits)
        Literally atMostKDistinct with k = 2. Call it and see.

     int characterReplacement(const string& s, int k)
        Valid when windowLength - maxFreq <= k.
        XXX: THINK -- maxFreq is never decreased when shrinking. Why is the answer
           still correct? (This one is genuinely subtle -- think it through.)

     int subarraysWithExactlyKDistinct(const vector<int>& nums, int k)
        exactly(K) = atMost(K) - atMost(K-1).
        Memorise this reduction. "Exactly" is almost never solved directly.

   WARN: TRAP -- edge cases: empty, all identical, k == 0, no valid window exists.
   XXX: THINK -- use if instead of while for the shrink and find an input that breaks it.
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 7 -- class BinarySearchPattern
   ==========================================================================
   TODO:
     int search(const vector<int>& nums, int target)
        mid = low + (high - low) / 2.
        WARN: TRAP -- NEVER (low + high) / 2 -- it overflows near INT_MAX.
        NOTE: INVARIANT -- the answer, if it exists, is always inside [low, high].
        Pair while (low <= high) with low = mid+1 / high = mid-1.

     int lowerBound(const vector<int>& nums, int target)   // first >= target
     int upperBound(const vector<int>& nums, int target)   // first >  target
        Write these by hand, then check against std::lower_bound/upper_bound.
        Pick ONE template for boundary searches and reuse it everywhere --
        improvising per problem is how people lose interviews.

   VARIATIONS:
     pair<int,int> firstAndLastPosition(const vector<int>& nums, int target)
        lowerBound and upperBound-1. Should be two lines once you have them.

     int searchRotated(const vector<int>& nums, int target)
        At any mid, one half IS sorted. Determine which, then decide whether
        the target lies inside it.

     int findMinRotated(const vector<int>& nums)

     int findPeakElement(const vector<int>& nums)
        Works on UNSORTED input. XXX: THINK -- what is the monotonic property here?

     int kokoEatingBananas(const vector<int>& piles, int h)
        BINARY SEARCH ON THE ANSWER. Search the speed range [1, maxPile],
        with a feasibility check as the comparator. This is the variation
        that actually shows up in interviews -- give it real time.

     int splitArrayLargestSum(const vector<int>& nums, int k)
        Same shape: "minimise the maximum". Recognise the phrasing.

   WARN: TRAP -- edge cases: empty, single element, target absent, target at either end,
               duplicates, all identical.
   XXX: THINK -- run (low + high) / 2 with low = high = 2e9. What happens?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 8 -- class DutchNationalFlag
   ==========================================================================
   TODO:
     void sortColors(vector<int>& nums)
        low / mid / high.  Loop while (mid <= high).
        NOTE: INVARIANT -- [0,low) == 0 | [low,mid) == 1 | [mid,high] == UNEXAMINED
                   | (high,n) == 2
            nums[mid] == 0 -> swap(low, mid), low++, mid++
            nums[mid] == 1 -> mid++
            nums[mid] == 2 -> swap(mid, high), high--     // mid does NOT move

   VARIATIONS:
     void threeWayPartition(vector<int>& nums, int pivot)
        Same routine around an arbitrary pivot. This is what lets quicksort
        survive arrays full of duplicates.

     int partitionTwoWay(vector<int>& nums, int pivot)
        The two-category version -- notice it collapses into Pattern 4.

     void countingSortTwoPass(vector<int>& nums)
        Write this too, so you can offer both. Counting sort is a fine
        answer; lead with it, then present DNF as the one-pass improvement.

   WARN: TRAP -- edge cases: empty, all 0s, all 2s, already sorted, reverse sorted.
   XXX: THINK -- THE question -- why does mid advance after the low-swap but not after
      the high-swap? Answer it in one sentence about examined vs unexamined
      regions.
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 9 -- class ArrayRotation
   ==========================================================================
   TODO:
     void rotateRight(vector<int>& nums, int k)
        WARN: TRAP -- k %= n FIRST (and guard n == 0), or you reverse past the end.
        NOTE: INVARIANT -- reversal is its own inverse -- that's why the three
                   reversals compose into a rotation.
        reverse whole -> reverse first k -> reverse the rest.

   VARIATIONS:
     void rotateLeft(vector<int>& nums, int k)
        Convert: left by k == right by n-k. Reuse the routine, don't rewrite.

     void rotateWithExtraArray(vector<int>& nums, int k)
        The O(n) space version. Write it so you can offer both and state
        the trade-off.

     void rotateJuggling(vector<int>& nums, int k)
        Cyclic replacement using gcd(n, k) to count the cycles. O(1) space
        like reversal, but far easier to get wrong. Know it exists; lead
        with reversal.

     void rotateMatrix90(vector<vector<int>>& mat)
        Transpose, then reverse each row. Same "compose two simple ops"
        flavour -- worth learning alongside.

   WARN: TRAP -- edge cases: k == 0, k == n, k > n, k negative, empty, single element.
   XXX: THINK -- skip k %= n and run it with k = 10 on a 3-element array. What happens?
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 10 -- class CyclicSort
   ==========================================================================
   The array's INDICES are the hash table. Value v lives at index v-1
   (for the range 1..n) or at index v (for 0..n-1). Decide which range you're
   in before writing a single line -- that confusion causes most of the bugs.

   TODO:
     void cyclicSort(vector<int>& nums)
        for each i: WHILE (nums[i] is in range && nums[i] != nums[home])
                        swap(nums[i], nums[home]);
        WARN: TRAP -- use while, not if -- one swap may displace another value.
        NOTE: INVARIANT -- after index i, nums[i] is either at its home or out of range.

   VARIATIONS:
     int missingNumber(const vector<int>& nums)
        Three ways -- write all three and compare:
          (a) cyclic sort then scan
          (b) XOR all indices with all values
          (c) Gauss: n*(n+1)/2 - actualSum
        XXX: THINK -- which one overflows for large n? Which destroys the input?

     vector<int> findDisappearedNumbers(vector<int> nums)
        SIGN MARKING: negate nums[abs(v)-1] to record "v was seen".
        Then any index still positive is missing. Use abs() when reading.

     int findDuplicate(const vector<int>& nums)
        Also solvable with Floyd's cycle detection by treating the array as
        a linked list -- and that version doesn't mutate the input at all.
        Worth writing both.

     vector<int> findAllDuplicates(vector<int> nums)
        Sign marking; an already-negative slot means you've seen it before.

     int firstMissingPositive(vector<int>& nums)
        The hard one. Cyclic sort ignoring everything outside 1..n, then
        scan for the first mismatch. Give this real time.

   WARN: TRAP -- edge cases: empty, single element, duplicates present, values out of range,
               zeros present (sign marking breaks on 0 -- why?).
   XXX: THINK -- the while inside the for looks O(n^2). Prove it's O(n).
   ========================================================================== */


/* ==========================================================================
   INFO: PATTERN 11 -- class XorTricks
   ==========================================================================
   INFO: everything here follows from:  a^a = 0,  a^0 = a,  and XOR is commutative
   and associative (so pairs cancel no matter where they sit).

   TODO:
     int singleNumber(const vector<int>& nums)
        Every element twice except one. XOR everything. One line.

   VARIATIONS:
     vector<int> singleNumberTwoUniques(const vector<int>& nums)
        XOR everything -> x^y. Any set bit in that result is a position where
        x and y differ. Isolate the lowest set bit with (diff & -diff), split
        the array into two groups by that bit, XOR each group.
        XXX: THINK -- what exactly does (diff & -diff) isolate, and why does it depend
           on two's-complement representation?

     int singleNumberThreeTimes(const vector<int>& nums)
        XOR does NOT work here -- triples don't cancel. Count set bits at
        each of the 32 positions and take the count mod 3.
        Try breaking it with plain XOR first so you see the failure.

     int swapWithoutTemp(int& a, int& b)

     vector<int> prefixXor(const vector<int>& nums)
     int rangeXor(const vector<int>& pre, int l, int r)
        pre[r+1] ^ pre[l]. Same algebra as prefix sums, because XOR undoes
        itself the way subtraction undoes addition.

   WARN: TRAP -- edge cases: single element, all identical pairs, zeros in the array.
   ========================================================================== */


/* ==========================================================================
   MAIN
   TODO: keep it this clean --

       PrefixSum().demo();
       Kadane().demo();
       TwoPointers().demo();
       WritePointer().demo();
       FixedWindow().demo();
       VariableWindow().demo();
       BinarySearchPattern().demo();
       DutchNationalFlag().demo();
       ArrayRotation().demo();
       CyclicSort().demo();
       XorTricks().demo();

   If loose test vectors start appearing down here, move them into the class
   they belong to.
   ========================================================================== */
int main() {


    return 0;
}
