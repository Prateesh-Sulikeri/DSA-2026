#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <ios>
#include <iterator>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

/*
    ==========================================================================
    CHAPTER 00.01 : ARRAYS  -  The Structure & Its Operations
    ==========================================================================

    SCOPE OF THIS FILE:
        The data structure itself and every operation on it. Nothing else.
        Patterns live next door in Patterns.md (theory) and Patterns.cpp
        (implementations). Don't solve problems here -- build the tool here.

    INFO: THE ONE IDEA
        An array is a CONTIGUOUS block of memory. That single fact explains
        every cost below. Index access is O(1) because the CPU just computes
            address = base + (index * sizeof(type))
        -- no searching involved. Insert/delete in the middle is O(n) for the
        same reason: contiguity must be preserved, so everything after the gap
        has to shift.

    COST TABLE (know this cold):
        Access by index      O(1)
        Search (unsorted)    O(n)
        Search (sorted)      O(log n)
        Insert/delete @ end  O(1) amortized
        Insert/delete @ mid  O(n)
        Space                O(n)

    REACH FOR IT WHEN:  index-based random access, bounded size, cache locality
    DON'T WHEN:         frequent mid insert/delete (list/deque), key lookup (map)

    --------------------------------------------------------------------------
    HOW TO USE THIS FILE:
        Work top to bottom. Each TODO is something you write. The comments give
        you the WHAT and the WHY -- the C++ is yours. Compile often:
            g++ -std=c++17 -Wall Arrays.cpp -o arrays && ./arrays
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
   HELPER
   TODO: printArray(const vector<int>& arr, const string& label = "")
         Prints the label then the elements. Write it first -- every demo
         below uses it.
   XXX: THINK -- why const& and not by value? (Part C answers this)
   -------------------------------------------------------------------------- */
    void printArray(const vector<int>& arr, const string& label = "") {
        if (!label.empty())
            cout << label << endl;
        cout << "[";
        bool first = true;
        for (const auto& i : arr) {
            if (!first)
                cout << ", ";
            first = false;
            cout << i;
        }
        cout << "]" << endl;
    }

    void print2DArray(const vector<vector<int>>& twoDVect, const string& label = "") {
        if (!label.empty())
            cout << label << endl;
        for (const auto& vec: twoDVect) {
            cout << "[";
            bool first = true;
            for (const auto& v: vec) {
                if (!first) {cout << ", ";}
                first = false;
                cout << v;
            }
            cout <<  "]" << endl;
        }
        cout << endl;
    }

/* ==========================================================================
   INFO: PART A -- DECLARATION, INITIALISATION, TRAVERSAL
   ==========================================================================
   TODO: void partA_basics()  -- print a demo for each item.

     A.1  C-style static array          int fixed[5] = {...};
          - get its length WITHOUT hardcoding 5
          - XXX: THINK -- why does that trick break the moment you pass it to a function?
               (what does the array "decay" into?)

     A.2  The four vector constructors
          - empty / sized-and-filled / init-list / copy-of-another

     A.3  A 2D vector (rows x cols, zero-filled)
          - this one-liner trips people up. Write it from memory.
          - XXX: THINK -- is a vector<vector<int>> actually contiguous? What does that
               cost you versus a flat vector with index = row * cols + col?

     A.4  Three traversal styles on the same vector
          - classic index loop
          - range-for by value      (read-only)
          - range-for by reference  (mutates -- prove it)

     A.5  at() vs []
          - one bounds-checks and throws, one is undefined behaviour.
            Know which is which, and when you'd actually want each.
   ========================================================================== */

    // Helper function for A.1
    void process(int arr[]) {
        // INFO: only the int* arrives here -- array-to-pointer decay. To keep the
        //       type and size, take a reference: void process(int (&arr)[5]).
        // XXX: Answer: sizeof(arr) / sizeof(arr[0]) would throw an compilation error here
        // INFO: CORRECTION -- not a compile error. It compiles (gcc only warns)
        //       and prints 2, not 5: a plausible-looking number that is silently
        //       garbage. That is exactly why decay is dangerous.
        // WARN: TRAP -- sizeof on an array PARAMETER measures the pointer, always.
        //
        // Commented out because they are the only -Wall noise in this file, and a
        // clean build is worth more than a demo we've already run. Uncomment to see
        // sizeof(arr)=8, sizeof(arr[0])=4, so the "length" comes out 2 instead of 5.
        // cout << "  sizeof(arr)               = " << sizeof(arr) << endl;
        // cout << "  sizeof(arr[0])            = " << sizeof(arr[0]) << endl;
        // cout << "  sizeof(arr)/sizeof(arr[0])= " << sizeof(arr) / sizeof(arr[0]) << endl;

        cout << "  the array decayed to this pointer: " << arr
             << "  (a bare address -- the size is gone)" << endl;
    }

    void partA_basics() {
        // XXX: A.1 C-style static array:
        cout << "A.1 C-style Static array functions: " << endl;
        int fixed[5] = {1, 2, 3, 4, 5};
        int length = sizeof(fixed) / sizeof(fixed[0]);

        cout << "fixed lenght array has a size of: " << length << endl;

        cout << "[";
        for (int i = 0 ; i < length ; i++) {
            cout << fixed[i];
            if (i+1 != length)
                cout << ", ";
        }
        cout << "]" << endl;

        process(fixed);
        cout << endl;

        // XXX: A.2 The four vector constructors
        // 1. Empty:
        cout << "A.2 The four vector constructors: " << endl << "1. Empty Vector: " << endl;
        vector<int> emptyVect;
        cout << "Size of empty Vector Constructor: " << emptyVect.size() << endl;
        cout << "Capacity of empty Vector Constructor: " << emptyVect.capacity() << endl;
        cout << endl;

        // 2. Sized + filled:
        cout << "2. Sized + filled Vector: " << endl;
        vector<int> filledVect(5, 42);
        printArray(filledVect, "Filled Vector contents: ");
        cout << "Size of filledVect: " << filledVect.size() << endl;
        cout << "Capacity of filledVect: " << filledVect.capacity() << endl;
        cout << endl;

        // 3. Initializer list:
        cout << "3. Initializer list Vector: " << endl;
        vector<int> initVect = {10, 20, 30, 40};
        printArray(initVect, "initVect elements are: ");
        cout << "Size of initVect: " << initVect.size() << endl;
        cout << "Capacity of initVect: " << initVect.capacity() << endl;
        cout << endl;

        // 4. Copy of Another vector:
        cout << "4. Copy of Another Vector: " << endl;
        vector<int> vectA = {10, 20, 30, 40};
        vector<int> vectB = vectA;
        printArray(vectA, "Contents of Vector A:");
        cout << endl;
        printArray(vectB, "Contents of Vector B:");

        cout << endl;

        cout << "Size of vectA: " << vectA.size() << endl;
        cout << "Capacity of vectA: " << vectA.capacity() << endl;

        cout << endl;

        cout << "Size of vectB: " << vectB.size() << endl;
        cout << "Capacity of vectB: " << vectB.capacity() << endl;
        cout << endl;

        // XXX: A.3  A 2D vector (rows x cols, zero-filled)
        cout << "A.3 A 2D Vector (Rows x Cols, zero filled): " << endl;
        vector<vector<int>> twoDVect(4, vector<int>(3, 0));
        print2DArray(twoDVect, "Printing the 2D Vector filled with 0's of 4 rows and 3 cols");
        cout << endl;

        // XXX: A.4  Three traversal styles on the same vector
        cout << "A.4  Three traversal styles on the same vector" << endl;
        vector<int> temp = {10, 20, 30, 40};
        // NOTE: narrowing size_t -> int, accepted deliberately for this demo.
        int tempSize = temp.size();
        // 1. Classic index loop:
        cout << "Traversal through classic index loop: " << endl;
        cout << "[";
        for (int i=0 ; i<tempSize ; i++) {
            cout << temp[i];
            if (i+1 != tempSize) cout << ", ";
        }
        cout << "]" << endl;
        cout << endl;

        // 2. Range-for by value:
        cout << "Traversal via range-by-value: " << endl;
        cout << "[";
        bool first = true;
        for (auto v: temp) {
            if (!first) cout << ", ";
            first = false;
            if(v == 10) v = 999;
            cout << v;
        }
        cout << "]" << endl;
        cout << "printing temp again: " << endl;
        printArray(temp);
        cout << "This proves that via range-by-value modification the temp vector didn't change" << endl;
        cout << endl;

        // 3. Range-for by reference
        cout << "Traversal via range-by-reference: " << endl;
        cout << "[";
        first = true;
        for (auto& v: temp) {
            if (!first) cout << ", ";
            first = false;
            if (v == 10) v = 11;
            cout << v;
        }
        cout << "]" << endl;
        cout << "printing temp again: " << endl;
        printArray(temp);
        cout << "This proves that via range-by-reference modification the temp vector did change" << endl;
        cout << endl;

        // XXX: A.5 at() vs []:
        cout << "A.5 at() vs []" << endl;
        vector<int> vectA4 = {10, 20, 30, 40};
        cout << "2nd Element accessed via [], in the vector is: " << vectA4[1] << endl;
        cout << "2nd Element accessed via .at(), in the vector is: " << vectA4.at(1) << endl;
        cout << endl;

        // Does NOT throw -- operator[] has no bounds check, so this is UB:
        // garbage, segfault, or apparently fine. The -Wall warning you'd get only
        // fires because the size is visible here; hide the index behind a variable
        // and the warning goes but the bug stays.
        // WARN: TRAP -- "it warned me" is not "it checked for me".
        // cout << "Trying out: vectA4[vectA4.size()]: " << vectA4[vectA4.size()] << endl;

        // Below code throws a runtime exception: throwing an instance of 'std::out_of_range'
        // cout << "Trying out: vectA4.at(vectA4.size()): " << vectA4.at(vectA4.size()) << endl;
    }

/* ==========================================================================
   INFO: PART B -- OPERATIONS: the STL toolkit you must know cold
   ==========================================================================
   TODO: void partB_operations()  -- print before/after so you SEE the effect.

     B.1  push_back, pop_back, size, empty, front, back, clear
     B.2  insert(pos, val) and erase(pos)   -- both O(n); demo at a middle index
     B.3  resize vs reserve  -- one changes size, one only capacity. Which?

     B.4  CAPACITY & GROWTH  (the interview question hiding in vectors)
          - print size() and capacity() inside a push_back loop and watch
            capacity jump
          - XXX: THINK -- push_back is "O(1) amortized". What actually happens on the
               slow calls, and why does doubling make the average O(1)?
          - XXX: THINK -- what is iterator invalidation, and which of the ops above
               can silently invalidate an iterator you're holding?

     B.5  sort (ascending AND descending), reverse
     B.6  accumulate -- note the third argument; it is NOT optional and it
          decides the return type. Classic overflow bug: accumulate(..., 0)
          over large values. Try it with a long long start value.
     B.7  max_element / min_element  -- these return ITERATORS. Dereference.
     B.8  count, find -- find returns end() when absent; test against end()
     B.9  binary_search / lower_bound / upper_bound  -- SORTED input only
          - lower_bound = first index with value >= target
          - upper_bound = first index with value >  target
          - XXX: THINK -- what does (upper_bound - lower_bound) give you, and why is
               that the standard way to count occurrences in a sorted array?
     B.10 the dedupe idiom on a sorted vector: erase + unique
          - XXX: THINK -- why is unique() alone not enough? What does it leave behind
               past the iterator it returns?
   ========================================================================== */

    void partB_operations() {
        // XXX: B.1 push_back, pop_back, size, empty, front, back, clear
        cout << "B.1 push_back, pop_back, size, empty, front, back, clear" << endl;
        vector<int> numbers = {1, 2, 3, 4, 5};
        printArray(numbers, "Numbers initial state: ");
        cout << "Size of numbers initially: " << numbers.size() << endl;
        cout << "Capacity of numbers initially: " << numbers.capacity() << endl;
        cout << endl;

        // 1. push_back
        cout << "Operation 1: push_back 6 & 7 into numbers: " << endl;
        numbers.push_back(6);
        numbers.push_back(7);
        printArray(numbers, "numbers after push_back 6 & 7: ");
        cout << endl;

        // 2. pop_back
        cout << "Operation 2: pop_back on numbers: " << endl;
        numbers.pop_back();
        printArray(numbers, "numbers after pop_back once: ");
        cout << endl;

        // 3. size:
        cout << "Size after above operations: " << numbers.size() << endl;
        cout << "Capacity after above operations: " << numbers.capacity() << endl;
        cout << endl;

        // 4. empty:
        cout << "is the given numbers vector empty: " << boolalpha << numbers.empty() << "\n\n";

        // 5. front:
        cout << "Front of the given numbers vector is: " << numbers.front() << "\n\n";

        // 6. back:
        cout << "Back of the given numbers vector is: " << numbers.back() << "\n\n";

        // 7. clear:
        printArray(numbers, "Before clear was called on numbers: ");
        cout << "Clearing the given numbers vector: "  << endl;
        numbers.clear();
        printArray(numbers, "After clear was called on numbers: ");
        cout << "Size after clear: " << numbers.size() << "\nCapacity after clear: " << numbers.capacity() << endl;
        // NOTE: INVARIANT -- clear() destroys the ELEMENTS, not the BUFFER.
        //       Only shrink_to_fit() offers the memory back, and it may decline.
        cout << endl;

        // XXX: B.2  insert(pos, val) and erase(pos)   -- both O(n); demo at a middle index
        // Operation 1:
        cout << "B.2  insert(pos, val) and erase(pos)" << endl;
        numbers = {1, 2, 3, 4, 5};
        printArray(numbers, "numbers before insert on 3rd index: ");
        // INFO: 99 not 3, so you can SEE 4 and 5 slide right. That slide is the O(n).
        numbers.insert(numbers.begin() + 3, 99);
        printArray(numbers, "numbers after insert on 3rd index: ");
        cout << endl;

        // Operation 2:
        printArray(numbers, "numbers before erase on pos 3: ");
        numbers.erase(numbers.begin() + 3);
        printArray(numbers, "numbers after erase on pos 3: " );
        cout << endl;

        // XXX: B.3  resize vs reserve  -- one changes size, one only capacity. Which?
        cout << "B.3  resize vs reserve" << endl;
        // Operation 1: resize: changes the size and adds desired elements in the new spaces
        printArray(numbers, "numbers before resize: ");
        cout << "Size of numbers before resize: " << numbers.size() << "\nCapacity of numbers before resize: " << numbers.capacity() << "\n\n";
        numbers.resize(10, 0);
        printArray(numbers, "numbers after resize: ");
        cout << "Size of numbers after resize: " << numbers.size() << "\nCapacity of numbers after resize: " << numbers.capacity() << "\n\n";
        // Shrinking using resize:
        numbers.resize(7);
        printArray(numbers, "numbers after shrinking resize(7): ");
        // NOTE: INVARIANT -- resize moves size (growing capacity only if it must);
        //       reserve moves capacity and never touches size.
        cout << "Size of numbers after shrink: " << numbers.size() << "\nCapacity of numbers after shrink: " << numbers.capacity() << "\n\n";
        cout << endl;

        // Operation 2: reserve: changes the overall capacity
        printArray(numbers, "numbers before reserve: ");
        cout << "Size of numbers before reserve: " << numbers.size() << "\nCapacity of numbers before reserve: " << numbers.capacity() << "\n\n";
        numbers.reserve(100);
        printArray(numbers, "numbers after reserve: ");
        cout << "Size of numbers after reserve: " << numbers.size() << "\nCapacity of numbers after reserve: " << numbers.capacity() << "\n\n";
        cout << endl;

        // XXX: B.4 CAPACITY & GROWTH
        // INFO: capacity below goes 1,2,4,8,16 -- copies across n push_backs
        //       total < 2n, i.e. O(n) spread over n calls = amortized O(1).
        // Operation 1: Capacity jump:
        cout << "B.4 CAPACITY & GROWTH" << endl;
        vector<int> nums;
        printArray(nums, "Initial elements in nums: ");
        cout << "Initial size of nums: " << nums.size() << "\nInitial Capacity of nums: " << nums.capacity() << endl;
        cout << endl;
        for (int i=0 ; i<10 ; i++) {
            nums.push_back(i);
            string msg = "Content of nums on iteration: " + to_string(i);
            printArray(nums, msg);
            cout << "on iteration: " << i << "\nSize of nums: " << nums.size() << "\nCapacity of nums: " << nums.capacity();
            cout << "\n\n";
        }
        cout << endl;

        // Operation 2: iterator invalidation:
        vector<int> nums2 = {10, 20, 30};
        nums2.reserve(4);
        // NOTE: INVARIANT -- the buffer moves if and only if a push_back would
        //       make size exceed capacity. All vector invalidation follows from
        //       that one rule. The two cases below are it with/without room.
        // Case 1: size 3 in capacity 4 -- there IS room, so push_back must not move.
        cout << "-- Case 1: room to spare --" << endl;
        printArray(nums2, "Initial elements in nums2: ");
        cout << "Size of nums2: " << nums2.size() << "\nCapacity of nums2: " << nums2.capacity();
        cout << "\n\n";
        auto oldAddress = &nums2[0];
        nums2.push_back(50);
        auto newAddress = &nums2[0];
        // WARN: TRAP -- in Case 2, fullAddress dangles the instant the realloc
        //       happens; even comparing it (not dereferencing) is formally
        //       unspecified. capacity() before vs after is the clean tell.
        cout << "Size is now " << nums2.size() << ", capacity still " << nums2.capacity() << endl;
        cout << "Address changed: " << (oldAddress != newAddress) << endl;
        cout << endl;

        // Case 2: after Case 1, nums2 is size 4 in capacity 4 -- FULL. Same four
        // lines, no reserve this time, so the next push_back has nowhere to go.
        cout << "-- Case 2: already full --" << endl;
        printArray(nums2, "Elements in nums2: ");
        cout << "Size of nums2: " << nums2.size() << "\nCapacity of nums2: " << nums2.capacity();
        cout << "\n\n";
        auto fullAddress = &nums2[0];
        nums2.push_back(60);
        auto grownAddress = &nums2[0];
        cout << "Size is now " << nums2.size() << ", capacity is now " << nums2.capacity() << endl;
        cout << "Address changed: " << (fullAddress != grownAddress) << endl;
        // INFO: the two results side by side ARE the lesson:
        //         Case 1  room to spare -> capacity same   -> address same
        //         Case 2  already full  -> capacity doubled -> address moved
        //       Case 2 reallocated, so every pointer/iterator into the old
        //       buffer (end() included) is dead. reserve(n) up front avoids it.
        cout << endl;

        // XXX: B.5  sort (ascending AND descending), reverse
        cout << "B.5  sort (ascending AND descending), reverse" << endl;
        vector<int> values = {10, 2, 1, 3, 7, 4, 1, 0};
        printArray(values, "Initial values vector: ");
        cout << endl;
        // Operation 1:
        sort(values.begin(), values.end());
        printArray(values, "After ascending sort: ");
        cout << endl;

        // Operation 2:
        sort(values.begin(), values.end(), greater<int>());
        printArray(values, "After descending sort: ");
        cout << endl;
        // Operation 3:
        // INFO: reversing the descending vector reproduces the ascending one --
        //       same output, O(n) not O(n log n). Sort when you don't know the
        //       order, reverse when you do. rbegin()/rend() is free.
        reverse(values.begin(), values.end());
        printArray(values, "After reverse: ");
        cout << "\n\n";

        // XXX: B.6 accumulate
        vector<int> vect = {10, 20, 30, 40};
        cout << "Result from accumulation 1: " << accumulate(vect.begin(), vect.end(), 0) << "\tof type: " << typeid(accumulate(vect.begin(), vect.end(), 0)).name() << endl;

        // WARN: TRAP -- the init value picks the ACCUMULATOR TYPE: 0 is int,
        //       0LL is long long. Same data, same call, one overflows. And that
        //       overflow is signed UB, not defined wraparound (unsigned wraps).
        vector<int> vect2 = {1'000'000'000, 1'000'000'000, 1'000'000'000, 1'000'000'000};
        cout << "Result from accumulation 2: " << accumulate(vect2.begin(), vect2.end(), 0) << "\tof type: " << typeid(accumulate(vect2.begin(), vect2.end(), 0)).name() << endl;
        cout << "Result from accumulation 2 with long long instead: " << accumulate(vect2.begin(), vect2.end(), 0LL) << "\tof type: " << typeid(accumulate(vect2.begin(), vect2.end(), 0LL)).name() << endl;
        cout << endl;

        // XXX: B.7  max_element / min_element
        cout << "B.7  max_element / min_element" << endl;
        auto maxElem = max_element(vect.begin(), vect.end());
        // max_element returns an iterator hence we need to dereference it to extract it's value
        cout << "Printing maxElem: " << *maxElem << endl;
        auto minElem = min_element(vect.begin(), vect.end());
        // Similarly min_elem returns and iterator too hence we need to dereference it
        cout << "Printing minElem: " << *minElem << "\n\n";

        // XXX: B.8  count, find
        // Opearation 1:
        cout << "B.8  count, find" << endl;
        vector<int> temp = {10, 10, 20, 10, 30, 10, 40, 10, 50, 10};
        auto count = std::count(temp.begin(), temp.end(), 10);
        cout << "count of 10's in temp: " << count << "\n\n";

        // Operation 2:
        // INFO: 30 hits, 300 misses -- looping over both makes both branches print.
        for (int target : {30, 300}) {
            auto pos = std::find(temp.begin(), temp.end(), target);
            if (pos != temp.end()) {
                auto idx = std::distance(temp.begin(), pos);
                cout << "Value " << target << " was found at index: " << idx << endl;
            } else {
                cout << "Value " << target << " not present in the given vector" << endl;
            }
        }
        // NOTE: INVARIANT -- find returns end() on a miss; end() is not an
        //       element. Test it BEFORE dereferencing or calling distance().
        // WARN: TRAP -- find is O(n) regardless of sorting. If sorted, use
        //       lower_bound (B.9) for the same answer in O(log n).
        cout << endl;

        // XXX: B.9  binary_search / lower_bound / upper_bound
        cout << "B.9  binary_search / lower_bound / upper_bound" << endl;
        // Operation 1: binary search
        vector<int> tempVect = {2, 5, 1, 3, 6, 10, 2, 8};
        sort(tempVect.begin(), tempVect.end());
        for (int target : {6, 30}) {
            bool isPresent = binary_search(tempVect.begin(), tempVect.end(), target);
            cout << "Is " << target << " present in the vector: " << (isPresent ? "True" : "False") << endl;
        }
        // WARN: TRAP -- binary_search answers yes/no only, never where.
        //       Need the position? lower_bound below, then check what it lands on.
        cout << endl;

        //Operation 2: lower_bound
        auto itr = lower_bound(tempVect.begin(), tempVect.end(), 2);
        auto idx = std::distance(tempVect.begin(), itr);
        cout << "Lower bound for given element in the vector appears at: " << idx << endl;
        cout << endl;

        // Operation 3: upper_bound
        auto upperItr = upper_bound(tempVect.begin(), tempVect.end(), 2);
        auto upperIdx = std::distance(tempVect.begin(), upperItr);
        cout << "Upper bound for given element in the vector appears at: " << upperIdx << endl;
        cout << "occurrences of 2: " << upperIdx - idx << endl;
        cout << endl;
        // NOTE: INVARIANT -- on sorted input, [lower_bound(x), upper_bound(x))
        //       is exactly the block equal to x -- empty if absent, and the
        //       insert position either way. equal_range returns both at once.
        // WARN: TRAP -- sorted input only. Unsorted doesn't error, it just lies.

        // XXX: B.10 the dedupe idiom on a sorted vector: erase + unique
        cout << "B.10 the dedupe idiom on a sorted vector: erase + unique" << endl;
        vector<int> newVect = {10, 2, 3, 1, 7, 13, 8, 6, 1, 2, 6, 10};
        printArray(newVect, "Initial newVect content: ");
        cout <<endl;
        sort(newVect.begin(), newVect.end());
        printArray(newVect, "After sort: ");
        cout << endl;
        // deduping the given vector now:
        // NOTE: INVARIANT -- unique() only removes ADJACENT duplicates. That's
        //       why the sort has to come first; without it you dedupe nothing.
        // XXX: Answer: I understand the concept I give you perms to make the code
        // better in this case. doesn't really make much difference right now for me
        // to invest more time. please complete it as you see fit

        // Step 1: unique() compacts survivors to the front and returns the new
        //         logical end. It only has an iterator pair -- no handle on the
        //         vector -- so it CANNOT change size. Hence step 2.
        auto newEnd = unique(newVect.begin(), newVect.end());
        cout << "size after unique(), before erase(): " << newVect.size()
             << "  <- unchanged, still 12" << endl;
        cout << "unique() survivors: " << std::distance(newVect.begin(), newEnd) << endl;
        printArray(newVect, "Whole vector after unique() -- note the junk tail: ");
        // WARN: TRAP -- everything from newEnd to end() is valid but UNSPECIFIED.
        //       It looks like plausible leftovers, so a glance at the front says
        //       "it worked". Never read it.

        // Step 2: erase() is what actually removes the tail and shrinks size.
        newVect.erase(newEnd, newVect.end());
        printArray(newVect, "After dedupe: ");
        cout << "size after erase(): " << newVect.size() << endl;
        // INFO: this two-step is the ERASE-REMOVE IDIOM -- same shape for
        //       remove() and remove_if(). C++20 folds it into std::erase/erase_if.
        cout << endl;
    }

/* ==========================================================================
   INFO: PART C -- PASSING ARRAYS TO FUNCTIONS
   ==========================================================================
   This is where silent O(n) costs hide. Write three tiny functions that each
   try to set v[0] = 999, taking the vector as:

     C.1  by value            vector<int> v
     C.2  by reference        vector<int>& v
     C.3  by const reference  const vector<int>& v   <- won't compile if you
                                                        try to modify. Good.

   TODO: void partC_passing() -- call all three on the same vector and PRINT
         after each. Seeing which one actually changed the caller's data is
         the entire lesson.

   Rule to internalise: const& is the default for read-only params. Plain &
   when you intend to mutate. By-value only when you deliberately want a copy.
   ========================================================================== */

    // INFO: printing vect.data() was a good instinct -- data() is the address
    //       of the underlying buffer, so byValue prints a DIFFERENT address (it
    //       got its own copy) while byReference and constRef print the caller's.
    //       That is the whole lesson of Part C in one line.
    //       Two notes: (a) label it, a bare 0x5f3a... says nothing on its own;
    //       (b) it only prints as an address because it is int*. A char* would
    //       be printed as a C string instead -- same operator, different meaning.
    void byValue(vector<int> vect) {
        vect[0] = 999;
        printArray(vect, "Vect when printed inside byValue: ");
        cout << vect.data() << endl;
    }

    void byReference(vector<int>& vect) {
        vect[0] = 999;
        printArray(vect, "Vect when printed inside byReference: ");
        cout << vect.data() << endl;
    }

    void constRef(const vector<int>& vect) {
        // WARN: Would give me compilation issues
        //vect[0] = 999;
        printArray(vect, "Vect when printed inside constRef: ");
        cout << vect.data() << endl;
    }

    void partC_passing() {
        vector<int> vect = {10, 20, 30, 40};
        printArray(vect, "Original vector: ");
        cout << endl;
        cout <<  "Passing by value: " << endl;
        byValue(vect);
        printArray(vect, "After byValue: ");
        cout << endl;
        cout << "Passing by reference: " << endl;
        byReference(vect);
        printArray(vect, "After byReference: ");
        cout << endl;
        vect[0] = 10;
        cout << "Passing to constant reference: " << endl;
        constRef(vect);
        printArray(vect, "After constRef: ");
        cout << "\n\n";
    }

/* ==========================================================================
   INFO: PART D -- BUILD YOUR OWN: class DynamicArray
   ==========================================================================
   This is the interview-level part. You cannot claim to know vectors until
   you've written one. Implement a growable int array over a raw pointer.

   TODO: class DynamicArray
       private:
           int* data;        // the heap buffer
           int  sz;          // how many elements the user has
           int  cap;         // how many the buffer can hold before regrowing

    XXX: THINK -- This is where you think

       public:
           DynamicArray(int initialCap = 4)   constructor -- allocate
           ~DynamicArray()                    destructor  -- delete[]. Don't leak.

           void push_back(int val)     append; grow if sz == cap
           void pop_back()             shrink logically; handle empty
           int& at(int index)          bounds-checked access (throw if bad)
           void insert(int index, int val)   O(n) -- shift right
           void erase(int index)             O(n) -- shift left
           int  size()  const
           int  capacity() const
           bool empty() const
           void print() const

       private:
           void resize(int newCap)     allocate new buffer, copy, delete old,
                                       repoint data and cap

   XXX: THINK -- THE QUESTIONS THAT MATTER
     - In resize(), what's the order of operations? Copy BEFORE delete[], and
       repoint data only after. Get it wrong and you read freed memory.
     - Why grow by DOUBLING rather than by +1 each time? Work out the total
       copy cost across n push_backs for both. That's the amortized O(1) proof.
     - at() returns int& (a reference). Why? What can the caller do with that
       which they couldn't with a plain int return?
     - Your class has a raw owning pointer. What happens on
           DynamicArray b = a;
       with the default copy constructor? (Look up "shallow copy" and the
       "Rule of Three" -- both objects end up owning the same buffer, and both
       destructors free it. Double free.)
       You don't have to implement the copy ctor + copy assignment today, but
       know that the gap exists and why.
   ========================================================================== */

    // NOTE: INVARIANT -- three things must hold at every point a caller can
    //       observe this object:
    //         1. data points to a buffer of exactly `cap` ints (never null)
    //         2. 0 <= sz <= cap
    //         3. data[0 .. sz-1] are the live elements; data[sz .. cap-1] is
    //            raw, unspecified memory -- never read it, never print it
    //       Every method below is a small transaction: it may break these in
    //       the middle, but it must restore all three before it returns. Most
    //       of the findings in this file are one of the three going unrestored.
    class DynamicArray {
        private:
            int* data;
            int sz;
            int cap;
        public:
            // INFO: start at a small NON-ZERO capacity so the first push_back is
            //       a plain write rather than an allocation. The 4 is arbitrary;
            //       what matters is that it isn't 0. See the BUG below for why.
            // INFO: neither ctor uses a member-init list:
            //           DynamicArray() : data(new int[4]), sz(0), cap(4) {}
            //       For plain ints this changes nothing at runtime, but it is the
            //       idiom, and it becomes mandatory the moment a member is const,
            //       a reference, or a type with no default constructor. Get in
            //       the habit here where it's free.
            DynamicArray() {
                int initCap = 4;
                data = new int[initCap] ;
                sz = 0;
                cap = initCap;
            }

            // INFO: this is the FILL constructor -- std::vector spells it
            //       vector<int> v(n, val). Good instinct to add it.
            // BUG: DynamicArray d(0, 7); leaves cap == 0. The next push_back does
            //      increaseCapacity -> cap = 0 * 2 = 0 -> resize(0) -> and then
            //      writes data[0] into a zero-length buffer. Confirmed under
            //      -fsanitize=address:
            //          heap-buffer-overflow ... WRITE of size 4 in push_back
            //      Doubling has a fixed point at zero. Two decisions to make:
            //      should cap == 0 be legal at all, and if it is, what must the
            //      growth expression do about it?
            // FIXME: this sz = 0 is dead -- you overwrite it with customCap five
            //        lines down. One assignment, not two.
            DynamicArray(int customCap, int val) {
                data = new int[customCap];
                sz = 0;
                for (int i=0 ; i<customCap ; i++) {
                    data[i] = val;
                }
                sz = customCap;
                cap = customCap;
            }

            ~DynamicArray() {
                delete[] data;
            }

            int size() const ;

            int capacity() const ;

            bool empty() const;

            // FIXME: `currCap` is a dead parameter. Every call site passes `cap`
            //        itself, so `currCap == cap` is always true and the guard
            //        guards nothing. A parameter that can only ever hold one
            //        value is not a parameter.
            // FIXME: this also mixes POLICY with MECHANISM. The policy is "when
            //        sz == cap, double"; the mechanism is resize(). Keep resize()
            //        dumb and put the policy in the callers, or make this
            //        `void grow()` taking nothing.
            // XXX: THINK -- write the single growth expression that is correct
            //      from cap == 4 AND from cap == 0. (This is the BUG above.)
            void increaseCapacity(int currCap) {
                if (currCap == cap) {
                    cap *= 2;
                }
                resize(cap);
            }

            // NOTE: INVARIANT -- the order here is the whole exercise: allocate,
            //       copy, THEN delete, THEN repoint. Delete before the copy and
            //       you read freed memory; repoint before the copy and you copy a
            //       buffer onto itself. You got this order right.
            // WARN: TRAP -- resize() is public and will happily SHRINK. resize(1)
            //       on a size-9 array sets cap = 1 while sz stays 9, so invariant
            //       #2 (sz <= cap) is dead and every read past index 0 is out of
            //       bounds. The scaffold put this under `private:` for exactly
            //       that reason. Move it back, or make it refuse newCap < sz.
            void resize(int newCap) {
                int* newData = new int[newCap];

                for (int i=0 ; i<sz ; i++) {
                    newData[i] = data[i];
                }

                delete[] data;
                data = newData;
                cap = newCap;
            }

            // INFO: amortized O(1). Almost every call is one write; one call in
            //       every `cap` pays for an O(n) copy. Because cap DOUBLES, the
            //       copies across n pushes total 1 + 2 + 4 + ... + n < 2n, so the
            //       average per push is a constant. Grow by +1 instead and that
            //       sum is 1 + 2 + ... + n = O(n^2). That is the entire argument
            //       for doubling, and it's the answer to the scaffold's question.
            // FIXME: both branches end in the same two lines. Grow first if you
            //        need to, then write once. Duplicated tails are where a later
            //        edit fixes one branch and quietly forgets the other.
            void push_back(int val) {
                if (sz < cap) {
                    data[sz] = val;
                    sz++;
                }
                else {
                    increaseCapacity(cap);
                    data[sz] = val;
                    sz++;
                }
            }

            // INFO: O(1), and shrinking LOGICALLY (sz-- only) is the right call.
            //       You deliberately do not free memory, so a push_back that
            //       follows costs nothing. std::vector does the same -- which is
            //       why shrink_to_fit() has to exist as a separate request.
            // WARN: TRAP -- data[sz] still holds the old value after this returns.
            //       It is not cleared; it is simply no longer yours to read. A
            //       print loop bounded by cap instead of sz will show it to you
            //       and it will look plausible.
            void pop_back() {
                if (sz == 0) {
                    return;
                }
                sz -=1 ;
            }

            // INFO: returning int& rather than int is what makes
            //           dArr.at(1) = 99;
            //       legal -- the caller gets a handle on the element itself, not
            //       a copy of its value. That's the scaffold's question answered.
            // FIXME: no const overload. A function taking `const DynamicArray&`
            //        cannot call at() at all right now. The pair you want is:
            //            int&       at(int index);
            //            const int& at(int index) const;
            // WARN: TRAP -- the returned reference dies the moment the buffer
            //       moves. Hold `int& r = dArr.at(0);`, push past capacity, and r
            //       dangles. This is precisely what "iterators and references are
            //       invalidated on reallocation" means in the std::vector docs.
            int& at(int index) {
                if (index < 0 || index >= sz) {
                    throw out_of_range("DynamicArray index out of range");
                }

                return data[index];
            }

            // FIXME: the delete[] / new[] pair buys nothing. sz = 0 on its own
            //        already satisfies all three invariants -- everything past sz
            //        is *defined* as garbage. You are paying for an allocation in
            //        order to produce garbage you were entitled to for free.
            // WARN: TRAP -- worse, it isn't exception safe. If that `new` throws,
            //       `data` has already been deleted and still points at freed
            //       memory, so the destructor frees it a second time. Never leave
            //       an owning member dangling between two statements that can throw.
            void clear() {
                delete[] data;
                data = new int[cap];
                sz = 0;
            }

            // NOTE: INVARIANT -- index == sz is LEGAL here, because inserting at
            //       the end is an append. That is why this bound is `> sz` while
            //       erase()'s is `>= sz`. They genuinely differ and you got both
            //       right -- make sure you can say why out loud.
            // INFO: O(n). The shift is the cost, and it walks BACKWARD from the
            //       last element so every write lands in a slot already copied.
            //       Forward would smear data[index] across the whole tail.
            // WARN: TRAP -- when sz == cap this grows the buffer, so any pointer
            //       or reference the caller was holding from at() now dangles.
            void insert(int index, int val) {
                if (index < 0 || index > sz) {
                    throw out_of_range("DynamicArray index out of range");
                }
                if (sz == cap) {
                    increaseCapacity(cap);
                }
                // [0, 1, 2, 3, 4] index 3 val 3
                for (int idx = (sz - 1) ; idx>=index ; idx--) {
                    data[idx+1] = data[idx];
                }
                sz++;
                data[index] = val;
            }

            // INFO: O(n). Shift LEFT, and forward this time, for the mirror
            //       reason. The loop stops at sz-2 so data[idx+1] never reads past
            //       the last live element -- an off-by-one here is the classic way
            //       to read one slot of garbage into your array.
            void erase(int index) {
                if (index < 0 || index >= sz) {
                    throw out_of_range("DynamicArray index out of range");
                }

                for (int idx = index ; idx < sz - 1 ; idx++) {
                    data[idx] = data[idx+1];
                }
                sz--;
            }

            // FIXME: not const -- the scaffold asked for `void print() const`.
            //        As written, a `const DynamicArray&` cannot print itself, so
            //        print() is unusable from any read-only function. Same fix
            //        as size()/capacity()/empty(), which you did mark const.
            // INFO: the loop bound is sz, not cap -- correct. Printing to cap
            //       would dump the raw tail, which is how invariant #3 usually
            //       announces itself: "weird numbers at the end of my array".
            void print() {
                cout << "[";
                for (int i=0 ; i < sz ; i++) {
                    cout << data[i];
                    if (i+1 != sz) {
                        cout << ", ";
                    }
                }
                cout << "]" << endl;
            }
    };

    int DynamicArray::size() const {
        return sz;
    }

    int DynamicArray::capacity() const {
        return cap;
    }

    // FIXME: `if (sz == 0) return true; return false;` is `return sz == 0;`
    //        -- the condition already IS the bool you're building.
    bool DynamicArray::empty() const {
        if (sz == 0) return true;
        return false;
    }

    // WARN: TRAP -- RULE OF THREE, still open. This class owns a raw pointer and
    //       declares a destructor, but no copy constructor and no copy
    //       assignment. So the compiler writes them for you, memberwise:
    //           DynamicArray b = a;     // b.data == a.data -- the SAME buffer
    //       and when both destructors run, one address is freed twice. Passing
    //       one of these BY VALUE does it silently -- which is exactly why Part C
    //       sits on the page before this one.
    //       You don't have to fix it today, but this file is not finished until
    //       you do: destructor, copy ctor, copy assignment -- declare all three
    //       or none. (Modern spelling: Rule of Five, adding the two moves.)

/* ==========================================================================
   MAIN
   TODO: call partA_basics(), partB_operations(), partC_passing(), then
         exercise DynamicArray -- push past the initial capacity so you can
         watch it grow, then insert/erase/at.
   ========================================================================== */
int main() {
    partA_basics();
    cout << "\n==============================================================\n\n\n";
    partB_operations();
    cout << "\n==============================================================\n\n\n";
    partC_passing();
    cout << "\n==============================================================\n\n\n";


    /* ----------------------------------------------------------------------
       INFO: PART D DEMO -- what the output has to prove

       FIXME: the demo below calls the methods but doesn't SHOW anything. Two
              problems, and both are about the reader rather than the code:

         1. Bare values. `cout << dArr.size()` prints "3". Three what? Every
            line needs to say what it is, and where it matters, what you
            expected of it:
                size after 3 push_backs: 3   (expected 3)
                capacity:                4   (expected 4 -- no growth yet)

         2. It never crosses a capacity boundary. You push 3 elements into a
            capacity of 4, so cap prints 4, then 4, then 4, and the doubling --
            the ONE idea Part D exists to teach -- never happens on screen.

       TODO: rewrite the demo so every block prints size AND capacity with a
             label, and so it covers:

               D.1  growth       push 1..9 in a loop, printing sz and cap after
                                 EACH push. The reader should watch cap go
                                 4, 4, 4, 4, 8, 8, 8, 8, 16 and be able to point
                                 at the two pushes that paid for a copy.
               D.2  at() reads   and then WRITES through it: dArr.at(1) = 99;
                                 print before and after -- that's the int&.
               D.3  at() throws  wrap a bad index in try/catch and print
                                 e.what(). An exception you never trigger is
                                 untested code.
               D.4  insert       at the FRONT (index 0), printing before and
                                 after so the shift is visible. Index 2 of a
                                 2-element array is just an append -- it proves
                                 nothing about shifting.
               D.5  erase        from the MIDDLE, same before/after.
               D.6  pop_back     on an empty array -- prove it returns quietly
                                 instead of driving sz negative.
               D.7  empty()      print it when it's true AND when it's false.
                                 (boolalpha is already on from Part A, so it
                                 prints true/false, not 1/0.)

       XXX: THINK -- a good demo reads like an argument: claim, evidence,
            verdict. Before writing each print, finish the sentence "this line
            proves that ___". If you can't finish it, the line is noise.

       XXX: THINK -- the four questions in the PART D header above are still
            unanswered. D.1's output is the evidence for the doubling one; write
            your answers back as `XXX: Answer:` lines under each question.
       ---------------------------------------------------------------------- */

    DynamicArray dArr;
    dArr.push_back(10);
    dArr.push_back(20);
    dArr.push_back(30);
    dArr.print();
    cout << dArr.size() <<  endl;
    cout << dArr.capacity() << endl;
    cout << endl;

    cout << dArr.at(1) << endl;
    cout << endl;

    dArr.pop_back();
    dArr.print();
    cout << dArr.size() <<  endl;
    cout << dArr.capacity() << endl;
    cout << endl;

    cout << dArr.empty() << endl;
    cout << endl;

    dArr.insert(2, 25);
    dArr.print();
    cout << endl;

    dArr.erase(2);
    dArr.print();
    cout << endl;
    return 0;
}
