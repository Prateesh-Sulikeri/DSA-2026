#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <functional>
#include <ios>
#include <iterator>
#include <numeric>
#include <ostream>
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

    void byValue(vector<int> vect) {
        vect[0] = 999;
        printArray(vect, "Vect when printed inside byValue: ");
    }

    void byReference(vector<int>& vect) {
        vect[0] = 999;
        printArray(vect, "Vect when printed inside byReference: ");
    }

    void constRef(const vector<int>& vect) {
        // WARN: Would give me compilation issues
        //vect[0] = 999;
        printArray(vect, "Vect when printed inside constRef: ");
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
    return 0;
}
