// LC 36 · Valid Sudoku · Medium
// Run: java ValidSudoku.java   (from "01-Arrays/03-Hashing/code/")

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ValidSudoku {
    // ===== SOLUTION =====
    static class Solution {
        public boolean isValidSudoku(char[][] board) {
            List<Set<Character>> rows = new ArrayList<>();
            List<Set<Character>> cols = new ArrayList<>();
            List<Set<Character>> boxes = new ArrayList<>(); // SC: O(3 × n × n) = O(n²), 3n sets of up to n digits each

            for (int i = 0; i < 9; i++) {
                rows.add(new HashSet<>());
                cols.add(new HashSet<>());
                boxes.add(new HashSet<>());
            } // TC: O(n), creates 3n empty sets

            for (int i=0 ; i<9 ; i++) {
                for (int j=0 ; j<9 ; j++) {
                    char c = board[i][j];

                    if (c == '.') continue;

                    int boxidx = (i/3) * 3 + (j/3);

                    if (!rows.get(i).add(c) ||
                        !cols.get(j).add(c) ||
                        !boxes.get(boxidx).add(c)
                    ) {
                        return false;
                    }
                }
            } // TC: O(n × n) × O(1) = O(n²), every cell once, each HashSet add is O(1) average
            return true;
        }
        // n = board side length (always 9 here, so really O(1) time and space)
        // TC: O(n²)
        // SC: O(n²)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] example1 = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
        };
        String[] example2 = example1.clone();
        example2[0] = "83..7....";   // 8 again in column 0 and in the top-left box

        check("example 1 (valid)", s.isValidSudoku(board(example1)), true);
        check("example 2 (8 twice in column 0)", s.isValidSudoku(board(example2)), false);
        check("empty board", s.isValidSudoku(board(cells())), true);
        check("same digit in a row", s.isValidSudoku(board(cells(0, 0, '5', 0, 8, '5'))), false);
        check("same digit in a column", s.isValidSudoku(board(cells(0, 0, '5', 8, 0, '5'))), false);
        check("same digit in a box only", s.isValidSudoku(board(cells(0, 0, '5', 1, 1, '5'))), false);
        check("same digit, different box", s.isValidSudoku(board(cells(0, 0, '5', 3, 3, '5'))), true);
        check("same digit, bottom-right box", s.isValidSudoku(board(cells(6, 6, '9', 8, 8, '9'))), false);
        check("valid but unsolvable still counts as valid", s.isValidSudoku(board(cells(0, 0, '1', 0, 1, '2', 1, 2, '3'))), true);
        done();
    }

    // board from 9 strings of 9 chars ('.' = empty)
    static char[][] board(String[] rows) {
        char[][] b = new char[9][];
        for (int r = 0; r < 9; r++) b[r] = rows[r].toCharArray();
        return b;
    }

    // empty board with digits placed at (row, col, digit) triples
    static String[] cells(Object... rcd) {
        char[][] b = new char[9][9];
        for (char[] row : b) java.util.Arrays.fill(row, '.');
        for (int i = 0; i < rcd.length; i += 3) b[(int) rcd[i]][(int) rcd[i + 1]] = (char) rcd[i + 2];
        String[] rows = new String[9];
        for (int r = 0; r < 9; r++) rows[r] = new String(b[r]);
        return rows;
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
