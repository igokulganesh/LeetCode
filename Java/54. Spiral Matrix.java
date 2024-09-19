import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();

        int m = matrix.length;
        int n = matrix[0].length;

        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;

        while (result.size() < m * n) {

            // move right
            for (int col = startCol; col <= endCol && result.size() < m * n; col++)
                result.add(matrix[startRow][col]);
            startRow++;

            // move down
            for (int row = startRow; row <= endRow && result.size() < m * n; row++)
                result.add(matrix[row][endCol]);
            endCol--;

            // move left
            for (int col = endCol; col >= startCol && result.size() < m * n; col--)
                result.add(matrix[endRow][col]);
            endRow--;

            // move up
            for (int row = endRow; row >= startRow && result.size() < m * n; row--)
                result.add(matrix[row][startCol]);
            startCol++;
        }

        return result;
    }
}