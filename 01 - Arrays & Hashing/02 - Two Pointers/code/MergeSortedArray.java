// LC 88 · Merge Sorted Array · Easy
// Run: java MergeSortedArray.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;

public class MergeSortedArray {
    // ===== SOLUTION =====
    static class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while (j >= 0) {
                if ( i>= 0 && nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i];
                    i--;
                }
                else {
                    nums1[k] = nums2[j];
                    j--;
                }
                k--;
            } // TC: O(m + n), m = valid length of nums1, n = length of nums2; one element placed per step, at most m + n steps
        }
        // TC: O(m + n)   (worst case: every nums1 element is larger, so all m move before nums2 runs out)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{1, 2, 3, 0, 0, 0}, 3, new int[]{2, 5, 6}, 3), "[1, 2, 2, 3, 5, 6]");
        check("example 2 (nums2 empty)", run(new int[]{1}, 1, new int[]{}, 0), "[1]");
        check("example 3 (nums1 empty)", run(new int[]{0}, 0, new int[]{1}, 1), "[1]");
        check("all of nums2 goes first", run(new int[]{4, 5, 6, 0, 0, 0}, 3, new int[]{1, 2, 3}, 3), "[1, 2, 3, 4, 5, 6]");
        check("all of nums2 goes last", run(new int[]{1, 2, 3, 0, 0, 0}, 3, new int[]{4, 5, 6}, 3), "[1, 2, 3, 4, 5, 6]");
        check("interleaved", run(new int[]{1, 3, 5, 0, 0, 0}, 3, new int[]{2, 4, 6}, 3), "[1, 2, 3, 4, 5, 6]");
        check("duplicates", run(new int[]{2, 2, 0, 0}, 2, new int[]{2, 2}, 2), "[2, 2, 2, 2]");
        check("negatives", run(new int[]{-1, 0, 0, 0}, 1, new int[]{-3, -2, 5}, 3), "[-3, -2, -1, 5]");
        check("nums1 has more", run(new int[]{1, 2, 4, 7, 0}, 4, new int[]{3}, 1), "[1, 2, 3, 4, 7]");
        done();
    }

    static String run(int[] nums1, int m, int[] nums2, int n) {
        new Solution().merge(nums1, m, nums2, n);
        return Arrays.toString(nums1);
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
