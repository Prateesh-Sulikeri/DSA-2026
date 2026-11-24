// LC 238 · Product of Array Except Self · Medium
// Run: java ProductOfArrayExceptSelf.java   (from "01-Arrays/04-Prefix-Sum/code/")

import java.util.Arrays;

public class ProductOfArrayExceptSelf {
    // ===== SOLUTION =====
    static class Solution {
        public int[] productExceptSelf(int[] nums) {
            int n = nums.length;

            int[] prefix = new int[n]; // SC: O(n)
            int[] suffix = new int[n]; // SC: O(n)

            Arrays.fill(prefix, 1); // TC: O(n)
            Arrays.fill(suffix, 1); // TC: O(n)

            for (int i = 1; i < n ; i++) {
                prefix[i] = prefix[i-1] * nums[i-1];
            } // TC: O(n)

            for (int i = n - 2 ; i>=0 ; i--) {
                suffix[i] = suffix[i+1] * nums[i+1];
            } // TC: O(n)

            int[] res = new int[n]; // SC: O(n)
            for (int i=0 ; i<n ; i++) {
                res[i] = prefix[i] * suffix[i];
            } // TC: O(n)

            return res;
        }
        // TC: O(5n) = O(n)   (2 fills + 3 loops)
        // SC: O(3n) = O(n)   (prefix + suffix + res; O(2n) extra if the output array isn't counted)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.productExceptSelf(new int[]{1, 2, 3, 4}), new int[]{24, 12, 8, 6});
        check("example 2", s.productExceptSelf(new int[]{-1, 1, 0, -3, 3}), new int[]{0, 0, 9, 0, 0});
        check("one zero", s.productExceptSelf(new int[]{2, 0, 5}), new int[]{0, 10, 0});
        check("two zeros", s.productExceptSelf(new int[]{0, 4, 0}), new int[]{0, 0, 0});
        check("negatives", s.productExceptSelf(new int[]{-2, -3, 4}), new int[]{-12, -8, 6});
        check("n = 2", s.productExceptSelf(new int[]{5, 7}), new int[]{7, 5});
        done();
    }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    static void check(String name, Object actual, Object expected) {
        total++;
        boolean ok = java.util.Objects.deepEquals(actual, expected);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + Arrays.toString((int[]) actual) + ", expected " + Arrays.toString((int[]) expected)));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
