class Solution {
    /*
     * Brute-Force Method
     * Time: O(3^(max(n, m)))
     * Space: O(m+n)
     */
    public int minDistance_1(String word1, String word2) {
        return minDistance_1(word1, word2, word1.length(), word2.length());
    }

    private int minDistance_1(String word1, String word2, int m, int n) {
        if (m == 0)
            return n;
        if (n == 0)
            return m;

        if (word1.charAt(m - 1) == word2.charAt(n - 1))
            return minDistance(word1, word2, m - 1, n - 1);

        int insert = minDistance(word1, word2, m, n - 1);
        int delete = minDistance(word1, word2, m - 1, n);
        int replace = minDistance(word1, word2, m - 1, n - 1);

        return 1 + Math.min(insert, Math.min(delete, replace));
    }

    /*
     * Brute-Force Method
     * Time: O(3^(max(n, m)))
     * Space: O(m+n)
     */
    public int minDistance_2(String word1, String word2) {
        return minDistance(word1, word2, 0, 0);
    }

    private int minDistance(String word1, String word2, int m, int n) {
        if (word1.length() == m)
            return word2.length() - n; // Insert remaining characters of word2
        if (word2.length() == n)
            return word1.length() - m; // Delete remaining characters of word1

        if (word1.charAt(m) == word2.charAt(n))
            return minDistance(word1, word2, m + 1, n + 1);

        int insert = minDistance(word1, word2, m, n + 1);
        int delete = minDistance(word1, word2, m + 1, n);
        int replace = minDistance(word1, word2, m + 1, n + 1);

        return 1 + Math.min(insert, Math.min(delete, replace));
    }

    /*
     * Top down dp
     * Time: O(n*m)
     * Space: O(m*n)
     */
    public int minDistance_3(String word1, String word2) {
        Integer[][] cache = new Integer[word1.length()][word2.length()];
        return minDistance(word1, word2, 0, 0, cache);
    }

    private int minDistance(String word1, String word2, int i, int j, Integer[][] cache) {
        if (word1.length() == i)
            return word2.length() - j; // Insert remaining characters of word2
        if (word2.length() == j)
            return word1.length() - i; // Delete remaining characters of word1

        if (cache[i][j] == null) {
            if (word1.charAt(i) == word2.charAt(j)) {
                cache[i][j] = minDistance(word1, word2, i + 1, j + 1, cache);
            } else {
                int insert = minDistance(word1, word2, i, j + 1, cache);
                int delete = minDistance(word1, word2, i + 1, j, cache);
                int replace = minDistance(word1, word2, i + 1, j + 1, cache);

                cache[i][j] = 1 + Math.min(insert, Math.min(delete, replace));
            }
        }

        return cache[i][j];
    }

    /*
     * Bottom Up DP
     * Time: O(n*m)
     * Space: O(m*n)
     */
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        int[][] cache = new int[m + 1][n + 1];

        // Base cases for converting an empty string to another string
        for (int i = 0; i <= m; i++)
            cache[i][0] = i; // All deletions

        for (int j = 0; j <= n; j++)
            cache[0][j] = j; // All insertions

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    cache[i][j] = cache[i - 1][j - 1];
                else {
                    int insert = cache[i][j - 1];
                    int delete = cache[i - 1][j];
                    int replace = cache[i - 1][j - 1];

                    cache[i][j] = 1 + Math.min(insert, Math.min(delete, replace));
                }
            }
        }

        return cache[m][n];
    }
}