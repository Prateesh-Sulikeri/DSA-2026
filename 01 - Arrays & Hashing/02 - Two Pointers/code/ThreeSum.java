// LC 15 · 3Sum · Medium
// Run: java ThreeSum.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    // ===== SOLUTION =====
    static class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            Arrays.sort(nums); // TC: O(n log n); SC: O(log n) sort stack
            List<List<Integer>> res = new ArrayList<>(); // SC: O(k) for the output only, k = number of triplets
            for (int i=0 ; i<nums.length ; i++) {
                if (i>0 && nums[i] == nums[i-1]) continue;

                int j = i+1;
                int k = nums.length-1;

                while (j<k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        j++;
                        k--;

                        while (j<k && nums[j] == nums[j-1]) j++;
                        while (j<k && nums[k] == nums[k+1]) k--;
                    }
                    else if (sum > 0) k--;
                    else j++;
                } // TC: O(n) j and k only move inward (amortised)
            } // TC: O(n) × O(n) -> O(n²)
            return res;
        }
        // TC: O(n log n) + O(n²) -> O(n²)
        // SC: O(log n), excluding the output
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", norm(s.threeSum(new int[]{-1, 0, 1, 2, -1, -4})), "[[-1, -1, 2], [-1, 0, 1]]");
        check("example 2 (no triplet)", norm(s.threeSum(new int[]{0, 1, 1})), "[]");
        check("example 3 (all zeros)", norm(s.threeSum(new int[]{0, 0, 0})), "[[0, 0, 0]]");
        check("many zeros, one triplet", norm(s.threeSum(new int[]{0, 0, 0, 0, 0})), "[[0, 0, 0]]");
        check("duplicate outer values", norm(s.threeSum(new int[]{-2, -2, 0, 0, 2, 2})), "[[-2, 0, 2]]");
        check("duplicate inner values", norm(s.threeSum(new int[]{-1, -1, -1, 2, 2})), "[[-1, -1, 2]]");
        check("several triplets", norm(s.threeSum(new int[]{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6})),
              "[[-4, -2, 6], [-4, 0, 4], [-4, 1, 3], [-4, 2, 2], [-2, -2, 4], [-2, 0, 2]]");
        check("all positive", norm(s.threeSum(new int[]{1, 2, 3})), "[]");
        done();
    }

    // Sort each triplet and the list, so the order of the output doesn't matter.
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
