
import java.util.HashSet;
import java.util.Set;

class Solution {
    /*
     * Time: O(m*n)
     * Space: O(m+n)
     */
    public void setZeroes_1(int[][] matrix) {
        Set<Integer> uniqueRows = new HashSet<>();
        Set<Integer> uniqueCols = new HashSet<>();

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    uniqueRows.add(i);
                    uniqueCols.add(j);
                }
            }
        }

        for (Integer row : uniqueRows) {
            for (int j = 0; j < matrix[0].length; j++)
                matrix[row][j] = 0;
        }

        for (Integer col : uniqueCols) {
            for (int i = 0; i < matrix.length; i++)
                matrix[i][col] = 0;
        }
    }

    /*
     * Time: O(m*n)
     * Space: O(1)
     */
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        boolean firstRow = false, firstCol = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;

                    if (i == 0)
                        firstRow = true;
                    if (j == 0)
                        firstCol = true;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (firstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}