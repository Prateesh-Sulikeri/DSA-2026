// LC 53 · Maximum Subarray (Kadane's Algorithm) · Medium
// Run: java MaximumSubarray.java   (from "01 - Arrays & Hashing/01 - Linear Scan/code/")

public class MaximumSubarray {
    // ===== SOLUTION =====
    static class Solution {
        public int maxSubArray(int[] nums) {
            int curSum = 0;
            int maxSum = Integer.MIN_VALUE;

            for (int n : nums) {
                curSum = Math.max(n, curSum + n);
                maxSum = Math.max(maxSum, curSum);
            } // TC: O(n)

            return maxSum;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.maxSubArray(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
        check("single element", s.maxSubArray(new int[]{1}), 1);
        check("all positive", s.maxSubArray(new int[]{5, 4, -1, 7, 8}), 23);
        check("all negative", s.maxSubArray(new int[]{-3, -1, -2}), -1);
        check("single negative", s.maxSubArray(new int[]{-5}), -5);
        check("zeros and negatives", s.maxSubArray(new int[]{0, -1, 0}), 0);
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
