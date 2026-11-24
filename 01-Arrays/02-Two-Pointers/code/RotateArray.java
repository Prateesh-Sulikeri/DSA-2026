// LC 189 · Rotate Array · Medium
// Run: java RotateArray.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.Arrays;

public class RotateArray {
    // ===== SOLUTION =====
    static class Solution {
        public void rotate(int[] nums, int k) {
            int n = nums.length;

            k %= n;

            reverseOrder(nums, 0, n-1); // TC: O(n)
            reverseOrder(nums, 0, k-1); // TC: O(k)
            reverseOrder(nums, k, n-1); // TC: O(n - k)
        }
        // TC: O(n) + O(k) + O(n - k) = O(2n) = O(n)   (every element is swapped twice)
        // SC: O(1)

        private void reverseOrder(int[] nums, int left, int right) {
            while (left < right) {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;

                left++;
                right--;
            } // TC: O(m), m = right - left + 1 = elements in the range (m / 2 swaps) · SC: O(1), only temp
        }
        // TC: O(m)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{1, 2, 3, 4, 5, 6, 7}, 3), "[5, 6, 7, 1, 2, 3, 4]");
        check("example 2 (negatives)", run(new int[]{-1, -100, 3, 99}, 2), "[3, 99, -1, -100]");
        check("k = 0", run(new int[]{1, 2, 3}, 0), "[1, 2, 3]");
        check("k = n (full turn)", run(new int[]{1, 2, 3}, 3), "[1, 2, 3]");
        check("k > n (k % n)", run(new int[]{1, 2, 3}, 4), "[3, 1, 2]");
        check("single element", run(new int[]{9}, 5), "[9]");
        check("n = 2, k = 1", run(new int[]{1, 2}, 1), "[2, 1]");
        check("duplicates", run(new int[]{1, 1, 2, 2}, 1), "[2, 1, 1, 2]");
        done();
    }

    static String run(int[] nums, int k) {
        new Solution().rotate(nums, k);
        return Arrays.toString(nums);
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
