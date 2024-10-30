class Solution {
    /*
     * Brutte-Force Approach
     * Time-Limit-Exceed
     * Time: O(2^n)
     * Space: O(n)
     */
    public int climbStairs_1(int n) {
        if (n <= 3)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    /*
     * DP Solution Top Down Solution
     * Time: O(n)
     * Space: O(n)
     */
    public int climbStairs_2(int n) {
        if (n <= 2)
            return n;

        int[] cache = new int[n + 1];
        cache[1] = 1;
        cache[2] = 2;

        return climbStairsUtil(n, cache);
    }

    private int climbStairsUtil(int n, int[] cache) {
        if (cache[n] == 0)
            cache[n] = climbStairsUtil(n - 1, cache) + climbStairsUtil(n - 2, cache);

        return cache[n];
    }

    /*
     * DP Bottom UP Solution
     * Time: O(n)
     * Space: O(n)
     */
    public int climbStairs_3(int n) {
        if (n <= 2)
            return n;

        int[] cache = new int[n + 1];
        cache[1] = 1;
        cache[2] = 2;

        for (int i = 3; i <= n; i++)
            cache[i] = cache[i - 1] + cache[i - 2];

        return cache[n];
    }

    /*
     * Space Optimal Solution
     * Time: O(n)
     * Space: O(1)
     */
    public int climbStairs(int n) {
        if (n <= 2)
            return n;

        int a = 1, b = 2, c = 0;

        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}