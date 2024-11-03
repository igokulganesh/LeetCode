import java.util.List;

class Solution {
    /*
     * Brute-Force Solution
     * Time: O(2^n)
     * Space: O(n)
     */
    public int minimumTotal_1(List<List<Integer>> triangle) {
        return minimumTotal(triangle, 0, 0);
    }

    public int minimumTotal(List<List<Integer>> triangle, int i, int j) {
        if (i == triangle.size() - 1)
            return triangle.get(i).get(j);

        int down = minimumTotal(triangle, i + 1, j);
        int right = minimumTotal(triangle, i + 1, j + 1);

        return triangle.get(i).get(j) + Math.min(down, right);
    }

    /*
     * Top-Down DP Solution
     * Time: O(n^2)
     * Space: O(n^2)
     */
    public int minimumTotal_2(List<List<Integer>> triangle) {
        int n = triangle.size();
        Integer[][] cache = new Integer[n][n];
        return minimumTotal(triangle, 0, 0, cache);
    }

    private int minimumTotal(List<List<Integer>> triangle, int i, int j, Integer[][] cache) {
        if (i == triangle.size() - 1)
            return triangle.get(i).get(j);

        if (cache[i][j] == null) {
            int down = minimumTotal(triangle, i + 1, j, cache);
            int right = minimumTotal(triangle, i + 1, j + 1, cache);

            cache[i][j] = triangle.get(i).get(j) + Math.min(down, right);
        }
        return cache[i][j];
    }

    /*
     * Bottom-Up DP Solution
     * Time: O(n^2)
     * Space: O(n^2)
     */
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] cache = new int[n][n];

        for (int col = 0; col < n; col++)
            cache[n - 1][col] = triangle.get(n - 1).get(col);

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                cache[row][col] = triangle.get(row).get(col) + Math.min(cache[row + 1][col], cache[row + 1][col + 1]);
            }
        }

        return cache[0][0];
    }
}