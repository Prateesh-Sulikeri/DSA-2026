// LC 680 · Valid Palindrome II · Easy
// Run: java ValidPalindromeII.java   (from "01-Arrays/02-Two-Pointers/code/")

public class ValidPalindromeII {
    // ===== SOLUTION =====
    static class Solution {
        public boolean validPalindrome(String s) {
            int i=0;
            int j=s.length()-1;

            while (i<=j) {
                if (s.charAt(i) == s.charAt(j)) {
                    i++;
                    j--;
                }
                else {
                    if (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1))
                        return true;
                    else
                        return false;
                } // TC: O(n) outer scan, plus at most 2 isPalindrome calls (only once, on first mismatch) × O(n)
            }
            return true;
        }
        // TC: O(n) + 2 × O(n) -> O(n)
        // SC: O(1)


        private boolean isPalindrome(String s, int i, int j) {
            while (i<=j) {
                if (s.charAt(i) == s.charAt(j)) {
                    i++;
                    j--;
                }
                else
                    return false;
            } // TC: O(n) i and j move inward
            return true;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1 (already a palindrome)", s.validPalindrome("aba"), true);
        check("example 2 (delete one)", s.validPalindrome("abca"), true);
        check("example 3 (impossible)", s.validPalindrome("abc"), false);
        check("single character", s.validPalindrome("a"), true);
        check("two different characters", s.validPalindrome("ab"), true);
        check("longer palindrome", s.validPalindrome("racecar"), true);
        check("must delete the right one", s.validPalindrome("cbbcc"), true);
        check("must delete the left one", s.validPalindrome("ccbbc"), true);
        check("delete the first character", s.validPalindrome("deeee"), true);
        check("needs two deletions", s.validPalindrome("abcda"), false);
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
