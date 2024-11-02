class Solution {

    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] cache = new boolean[n][n];

        int maxLen = 1;
        int start = 0;

        // Single character substrings are palindromes
        for (int i = 0; i < n; i++)
            cache[i][i] = true;

        // Check for palindromic substrings of length 2 and greater
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    if (len == 2 || cache[i + 1][j - 1]) {
                        cache[i][j] = true;
                        if (len > maxLen) {
                            maxLen = len;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substring(start, start + maxLen);
    }
}