#include <bits/stdc++.h>
#include <ios>
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
        // INFO: This would only send the int* pointer because of Array-to-pointer decay. if we need array to retain the array type/size then we would need to pass it by reference making the function signature: void process(int (&arr)[5])
        // XXX: Answer: sizeof(arr) / sizeof(arr[0]) would throw an compilation error here
        // INFO: CORRECTION -- not a compile error. It COMPILES (gcc only warns,
        //       -Wsizeof-array-argument) and prints 2, as the output below shows.
        //       A compile error would be the merciful outcome; instead you get a
        //       plausible-looking number that is silently garbage, and the bug
        //       ships. THAT is why decay is dangerous -- so you pass a size
        //       alongside the pointer, take int (&arr)[5], or just use vector.
        // WARN: TRAP -- sizeof on an array PARAMETER measures the pointer, always.
        //
        // The three lines below are commented out ON PURPOSE: they are the proof,
        // but they are also the one thing in this file that makes -Wall noisy
        // (-Wsizeof-array-argument, twice). A clean build is the signal that
        // nothing is wrong, so we don't spend it on a demo we've already run.
        // Uncomment, build, read the output, comment them back:
        //
        //     sizeof(arr)                = 8   <- an int*, not the array
        //     sizeof(arr[0])             = 4
        //     sizeof(arr)/sizeof(arr[0]) = 2   <- WRONG, should be 5
        //
        // cout << "  sizeof(arr)               = " << sizeof(arr) << endl;
        // cout << "  sizeof(arr[0])            = " << sizeof(arr[0]) << endl;
        // cout << "  sizeof(arr)/sizeof(arr[0])= " << sizeof(arr) / sizeof(arr[0]) << endl;

        cout << "  the array decayed to this pointer: " << arr
             << "  (a bare address -- the size is gone)" << endl;
    }

    void partA_basics() {
        // INFO: bare XXX: below is YOUR marker -- settled convention, see the
        //       legend up top. Mine always carry a second word (XXX: THINK --).
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

        // Below code does NOT throw. operator[] has no bounds check at all, so
        // out-of-range [] is undefined behaviour: garbage, segfault, or apparently
        // fine. Uncommenting it only gets you a -Wall compile-time WARNING
        // ("array subscript 4 is outside array bounds"), and that fires purely
        // because the size is visible right here -- hide the index behind a
        // variable and the warning disappears while the bug stays.
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
       cout << endl;

       // XXX: B.2  insert(pos, val) and erase(pos)   -- both O(n); demo at a middle index
       // Operation 1:
       cout << "B.2  insert(pos, val) and erase(pos)" << endl;
       numbers = {1, 2, 3, 4, 5};
       printArray(numbers, "numbers before insert on 3rd index: ");
       numbers.insert(numbers.begin() + 3, 3);
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
       cout << endl;

       // Operation 2: reserve: changes the overall capacity
       printArray(numbers, "numbers before reserve: ");
       cout << "Size of numbers before reserver: " << numbers.size() << "\nCapacity of numbers before reserve: " << numbers.capacity() << "\n\n";
       numbers.reserve(100);
       printArray(numbers, "numbers after reserve: ");
       cout << "Size of numbers after reserve: " << numbers.size() << "\nCapacity of numbers after reserve: " << numbers.capacity() << "\n\n";
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
    return 0;
}
