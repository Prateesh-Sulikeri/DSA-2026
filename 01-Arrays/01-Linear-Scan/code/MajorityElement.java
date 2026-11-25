// LC 169 · Majority Element · Easy
// Run: java MajorityElement.java   (from "01-Arrays/01-Linear-Scan/code/")

import java.util.HashMap;
import java.util.Map;

public class MajorityElement {
    // ===== SOLUTION =====
    static class Solution {
        public int majorityElement(int[] nums) {
            Map<Integer, Integer> freqMap = new HashMap<>(); // SC: O(m), m = number of distinct values

            for (int n : nums) {
                int freq = freqMap.getOrDefault(n, 0) + 1 ;
                freqMap.put(n, freq);

                if (freq > nums.length / 2)
                    return n;
            } // TC: O(n)
            return 0;
        }
        // TC: O(n)
        // SC: O(m)

        public int majorityElement2(int[] nums) {
             int candidate = 0, count = 0; // SC: O(1)

             for (int n : nums) {
                 if (count == 0 ) candidate = n;

                 count += (n == candidate) ? 1 : -1;
             } // TC: O(n)
             return candidate;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.majorityElement(new int[]{3, 2, 3}), 3);
        check("example 2", s.majorityElement(new int[]{2, 2, 1, 1, 1, 2, 2}), 2);
        check("single element", s.majorityElement(new int[]{7}), 7);
        check("all the same", s.majorityElement(new int[]{4, 4, 4, 4}), 4);
        check("majority at the end", s.majorityElement(new int[]{1, 2, 2}), 2);

        check("example 1", s.majorityElement2(new int[]{3, 2, 3}), 3);
        check("example 2", s.majorityElement2(new int[]{2, 2, 1, 1, 1, 2, 2}), 2);
        check("single element", s.majorityElement2(new int[]{7}), 7);
        check("all the same", s.majorityElement2(new int[]{4, 4, 4, 4}), 4);
        check("majority at the end", s.majorityElement2(new int[]{1, 2, 2}), 2);
        done();
    }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    static void check(String name, Object actual, Object expected) {
        total++;
        boolean ok = java.util.Objects.deepEquals(actual, expected);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + actual + ", expected " + expected));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
