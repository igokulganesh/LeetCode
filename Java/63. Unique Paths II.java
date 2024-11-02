import java.util.Arrays;

class Solution {
    /*
     * Brute-Force-Method
     * Time: O(2^(m+n))
     * Space: O(m+n)
     */
    public int uniquePathsWithObstacles_1(int[][] grid) {
        return uniquePathUtil(grid, 0, 0);
    }

    private int uniquePathUtil(int[][] grid, int i, int j) {
        if (i == grid.length || j == grid[0].length || grid[i][j] == 1)
            return 0;

        if (i == grid.length - 1 && j == grid[0].length - 1)
            return 1;

        return uniquePathUtil(grid, i + 1, j) + uniquePathUtil(grid, i, j + 1);
    }

    /*
     * DP-Top-Down
     * Time: O((m*n))
     * Space: O(m*n)
     */
    public int uniquePathsWithObstacles_2(int[][] grid) {
        int[][] cache = new int[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++)
            Arrays.fill(cache[i], -1);

        return uniquePathUtil(grid, 0, 0, cache);
    }

    private int uniquePathUtil(int[][] grid, int i, int j, int[][] cache) {
        if (i == grid.length || j == grid[0].length || grid[i][j] == 1)
            return 0;

        if (i == grid.length - 1 && j == grid[0].length - 1)
            return 1;

        if (cache[i][j] == -1)
            cache[i][j] = uniquePathUtil(grid, i + 1, j, cache) + uniquePathUtil(grid, i, j + 1, cache);

        return cache[i][j];
    }

    /*
     * DP-Bottom-Up
     * Time: O((m*n))
     * Space: O(m*n)
     */
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] cache = new int[m][n];

        // fill the 1st row
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                cache[i][0] = 1;
            else
                break;
        }

        // fill the 1st col
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0)
                cache[0][j] = 1;
            else
                break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 0)
                    cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
            }
        }

        return cache[m - 1][n - 1];
    }
}
