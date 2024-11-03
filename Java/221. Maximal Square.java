class Solution {
    /*
     * Brute-Force Method
     * Time: O(3^(m*n))
     * Space: O(m+n)
     */
    public int maximalSquare_1(char[][] matrix) {
        int maximum = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == '1')
                    maximum = Math.max(maximum, maximalSquare(matrix, i, j));
            }
        }
        return maximum * maximum;
    }

    public int maximalSquare(char[][] matrix, int i, int j) {
        if (i == matrix.length || j == matrix[0].length || matrix[i][j] == '0')
            return 0;

        int right = maximalSquare(matrix, i + 1, j);
        int down = maximalSquare(matrix, i, j + 1);
        int diagonal = maximalSquare(matrix, i + 1, j + 1);

        return 1 + Math.min(right, Math.min(down, diagonal));
    }

    /*
     * Top down dp Method
     * Time: O(m*n)
     * Space: O(m*n)
     */
    public int maximalSquare_2(char[][] matrix) {
        Integer[][] cache = new Integer[matrix.length][matrix[0].length];

        int maximum = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == '1')
                    maximum = Math.max(maximum, maximalSquare(matrix, i, j, cache));
            }
        }
        return maximum * maximum;
    }

    private int maximalSquare(char[][] matrix, int i, int j, Integer[][] cache) {
        if (i == matrix.length || j == matrix[0].length || matrix[i][j] == '0')
            return 0;

        if (cache[i][j] == null) {
            int right = maximalSquare(matrix, i + 1, j, cache);
            int down = maximalSquare(matrix, i, j + 1, cache);
            int diagonal = maximalSquare(matrix, i + 1, j + 1, cache);

            cache[i][j] = 1 + Math.min(right, Math.min(down, diagonal));
        }
        return cache[i][j];
    }

    /*
     * Bottom dp Method
     * Time: O(m*n)
     * Space: O(m*n)
     */
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] cache = new int[m][n];

        int maximum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    cache[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else if (matrix[i][j] == '1')
                    cache[i][j] = 1 + Math.min(cache[i - 1][j], Math.min(cache[i][j - 1], cache[i - 1][j - 1]));

                maximum = Math.max(maximum, cache[i][j]);
            }
        }

        return maximum * maximum;
    }
}