// LC 242 · Valid Anagram · Easy
// Run: java ValidAnagram.java   (from "01 - Arrays & Hashing/03 - Hashing/code/")

import java.util.Arrays;

public class ValidAnagram {
    // ===== SOLUTION =====
    static class Solution {
        // Approach 1: sort both strings, then compare
        public boolean isAnagramSort(String s, String t) {
            if (s.length() != t.length())
                return false;

            char[] sArr = s.toCharArray();
            char[] tArr = t.toCharArray();

            Arrays.sort(sArr);
            Arrays.sort(tArr);

            return Arrays.equals(sArr, tArr);
        }

        // Approach 2: count array (int[26])
        public boolean isAnagramCount(String s, String t) {
            if (s.length() != t.length())
                return false;

            int[] charArr = new int[26];

            for (int i=0 ; i<s.length() ; i++) {
                charArr[s.charAt(i) - 'a']++;
                charArr[t.charAt(i) - 'a']--;
            }

            for (int count : charArr) {
                if (count != 0)
                    return false;
            }

            return true;
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        String[][] cases = {
            // name, s, t, expected
            {"example 1", "anagram", "nagaram", "true"},
            {"example 2", "rat", "car", "false"},
            {"different lengths", "a", "ab", "false"},
            {"same letters, different counts", "aab", "abb", "false"},
            {"identical strings", "listen", "listen", "true"},
            {"single character", "z", "z", "true"},
            {"one letter repeated", "aaaa", "aaaa", "true"},
            {"all 26 letters, reversed", "abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba", "true"},
        };
        for (String[] c : cases) {
            boolean expected = Boolean.parseBoolean(c[3]);
            check("sort  · " + c[0], s.isAnagramSort(c[1], c[2]), expected);
            check("count · " + c[0], s.isAnagramCount(c[1], c[2]), expected);
        }
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
