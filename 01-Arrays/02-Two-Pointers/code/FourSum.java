// LC 18 · 4Sum · Medium
// Run: java FourSum.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FourSum {
    // ===== SOLUTION =====
    static class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {

            int n = nums.length;
            List<List<Integer>> res = new ArrayList<>(); // SC: O(k) for the output only, k = number of quadruplets
            Arrays.sort(nums); // TC: O(n log n); SC: O(log n) sort stack

            for (int i=0 ; i<n - 3 ; i++) {
                if (i>0 && nums[i] == nums[i-1]) continue;

                for (int j=i+1 ; j<n - 2 ; j++) {
                    if (j>i+1 && nums[j] == nums[j-1]) continue;

                    int k = j+1;
                    int l = n-1;

                    while (k < l) {
                        long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            res.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));

                            k++;
                            l--;

                            while (k<l && nums[k] == nums[k-1]) k++;
                            while (k<l && nums[l] == nums[l+1]) l--;
                        }

                        else if (sum > target)
                            l--;
                        else
                            k++;
                    } // TC: O(n) k and l only move inward (amortised)
                } // TC: O(n) × O(n) -> O(n²)
            } // TC: O(n) × O(n²) -> O(n³)
            return res;
        }
        // TC: O(n log n) + O(n³) -> O(n³)
        // SC: O(log n), excluding the output
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", norm(s.fourSum(new int[]{1, 0, -1, 0, -2, 2}, 0)),
              "[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]");
        check("example 2 (all the same)", norm(s.fourSum(new int[]{2, 2, 2, 2, 2}, 8)), "[[2, 2, 2, 2]]");
        check("fewer than 4 elements", norm(s.fourSum(new int[]{1, 2, 3}, 6)), "[]");
        check("no quadruplet", norm(s.fourSum(new int[]{1, 2, 3, 4}, 100)), "[]");
        check("duplicate second values", norm(s.fourSum(new int[]{-1, 0, 0, 0, 0, 1}, 0)),
              "[[-1, 0, 0, 1], [0, 0, 0, 0]]");
        check("int overflow", norm(s.fourSum(new int[]{1000000000, 1000000000, 1000000000, 1000000000}, -294967296)), "[]");
        check("negative target", norm(s.fourSum(new int[]{-3, -2, -1, 0, 0, 1, 2, 3}, -5)),
              "[[-3, -2, -1, 1], [-3, -2, 0, 0]]");
        done();
    }

    // Sort each quadruplet and the list, so the order of the output doesn't matter.
    static String norm(List<List<Integer>> res) {
        List<List<Integer>> copy = new ArrayList<>();
        for (List<Integer> t : res) {
            List<Integer> c = new ArrayList<>(t);
            c.sort(null);
            copy.add(c);
        }
        copy.sort((a, b) -> {
            for (int k = 0; k < Math.min(a.size(), b.size()); k++)
                if (!a.get(k).equals(b.get(k))) return a.get(k) - b.get(k);
            return a.size() - b.size();
        });
        return copy.toString();
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
