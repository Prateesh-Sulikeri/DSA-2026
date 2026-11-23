// LC 881 · Boats to Save People · Medium
// Run: java BoatsToSavePeople.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;

public class BoatsToSavePeople {
    // ===== SOLUTION =====
    static class Solution {
        public int numRescueBoats(int[] people, int limit) {

            Arrays.sort(people); // TC: O(n log n); SC: O(log n) sort stack
            int boats = 0;

            int left = 0;
            int right = people.length - 1;

            while (left <= right) {
                if (people[left] + people[right] <= limit)
                    left++;

                right--;
                boats++;
            } // TC: O(n) each iteration shrinks right, left only moves forward
            return boats;
        }
        // TC: O(n log n) sorting dominates
        // SC: O(log n)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.numRescueBoats(new int[]{1, 2}, 3), 1);
        check("example 2", s.numRescueBoats(new int[]{3, 2, 2, 1}, 3), 3);
        check("example 3", s.numRescueBoats(new int[]{3, 5, 3, 4}, 5), 4);
        check("single person", s.numRescueBoats(new int[]{5}, 5), 1);
        check("nobody can pair", s.numRescueBoats(new int[]{4, 4, 4}, 5), 3);
        check("everyone pairs", s.numRescueBoats(new int[]{1, 1, 1, 1}, 2), 2);
        check("unsorted, heavy + light pairs", s.numRescueBoats(new int[]{5, 1, 4, 2}, 6), 2);
        check("odd count, one rides alone", s.numRescueBoats(new int[]{1, 2, 3}, 3), 2);
        check("pair hits the limit exactly", s.numRescueBoats(new int[]{2, 3}, 5), 1);
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
