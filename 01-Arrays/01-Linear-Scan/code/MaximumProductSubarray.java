// LC 152 · Maximum Product Subarray · Medium
// Run: java MaximumProductSubarray.java   (from "01-Arrays/01-Linear-Scan/code/")

public class MaximumProductSubarray {
    // ===== SOLUTION =====
    static class Solution {
        public int maxProduct(int[] nums) {
            int maxProd = nums[0];
            int minProd = nums[0];

            int res = nums[0];

            for (int i=1 ; i<nums.length ; i++) {
                int curr = nums[i];

                if (curr < 0) {
                    int temp = maxProd;
                    maxProd = minProd;
                    minProd = temp;
                }

                maxProd = Math.max(curr, maxProd * curr);
                minProd = Math.min(curr, minProd * curr);

                res = Math.max(res, maxProd);
            } // TC: O(n)

            return res;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.maxProduct(new int[]{2, 3, -2, 4}), 6);
        check("example 2 (zero splits)", s.maxProduct(new int[]{-2, 0, -1}), 0);
        check("single element", s.maxProduct(new int[]{-3}), -3);
        check("two negatives flip to positive", s.maxProduct(new int[]{-2, 3, -4}), 24);
        check("all negative, odd count", s.maxProduct(new int[]{-1, -2, -3}), 6);
        check("zero in the middle", s.maxProduct(new int[]{2, -5, 0, 3, 4}), 12);
        check("all zeros", s.maxProduct(new int[]{0, 0}), 0);
        check("negative then zero", s.maxProduct(new int[]{-2, 0}), 0);
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
