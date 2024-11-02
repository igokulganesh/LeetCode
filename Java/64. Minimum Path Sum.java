import java.util.Arrays;

class Solution {
    /*
     * Brute-Force Method
     * Time: O(2^(m+n))
     * Space: O(m+n)
     */
    public int minPathSum_1(int[][] grid) {
        return minPathSum(grid, 0, 0);
    }

    private int minPathSum(int[][] grid, int i, int j) {
        if (i == grid.length - 1 && j == grid[0].length - 1)
            return grid[i][j];

        if (i == grid.length || j == grid[0].length)
            return Integer.MAX_VALUE;

        int down = minPathSum(grid, i + 1, j);
        int right = minPathSum(grid, i, j + 1);

        return grid[i][j] + Math.min(down, right);
    }

    /*
     * DP Top down method
     * Time: O(m×n)
     * Space: O(m×n)
     */
    public int minPathSum_2(int[][] grid) {
        int[][] cache = new int[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++)
            Arrays.fill(cache[i], -1);

        return minPathSum(grid, 0, 0, cache);
    }

    private int minPathSum(int[][] grid, int i, int j, int[][] cache) {
        if (i == grid.length - 1 && j == grid[0].length - 1)
            return grid[i][j];

        if (i == grid.length || j == grid[0].length)
            return Integer.MAX_VALUE;

        if (cache[i][j] == -1) {
            int down = minPathSum(grid, i + 1, j, cache);
            int right = minPathSum(grid, i, j + 1, cache);
            cache[i][j] = grid[i][j] + Math.min(down, right);
        }
        return cache[i][j];
    }

    /*
     * DP Bottom Up Method
     * Time: O(m×n)
     * Space: O(m×n)
     */
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] cache = new int[m][n];
        cache[0][0] = grid[0][0];

        // fill the 1st row
        for (int i = 1; i < m; i++)
            cache[i][0] = cache[i - 1][0] + grid[i][0];

        // fill the 1st col
        for (int j = 1; j < n; j++)
            cache[0][j] = cache[0][j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cache[i][j] = grid[i][j] + Math.min(cache[i - 1][j], cache[i][j - 1]);
            }
        }
        return cache[m - 1][n - 1];
    }
}