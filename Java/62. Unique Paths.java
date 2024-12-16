class Solution {
    /*
     * Brute-force
     */
    public int uniquePaths_1(int m, int n) {
        return uniquePaths(m, n, 0, 0);
    }

    public int uniquePaths(int m, int n, int i, int j) {
        if (m == i + 1 && n == j + 1)
            return 1;

        if (m == i || n == j)
            return 0;

        return uniquePaths(m, n, i + 1, j) + uniquePaths(m, n, i, j + 1);
    }

    /*
     * Top Down Dp Solution
     */
    public int uniquePaths_2(int m, int n) {
        Integer[][] dp = new Integer[m][n];
        return uniquePaths(m, n, 0, 0, dp);
    }

    public int uniquePaths(int m, int n, int i, int j, Integer[][] dp) {
        if (m == i + 1 && n == j + 1)
            return 1;

        if (m == i || n == j)
            return 0;

        if (dp[i][j] == null)
            dp[i][j] = uniquePaths(m, n, i + 1, j, dp) + uniquePaths(m, n, i, j + 1, dp);

        return dp[i][j];
    }

    /*
     * Bottom Up Solution
     */
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
}