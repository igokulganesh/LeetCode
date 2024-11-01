import java.util.Arrays;

class Solution {

    /*
     * Greedy Approach
     * Not Always work
     */
    public int coinChange_1(int[] coins, int amount) {
        Integer[] coinsArray = Arrays.stream(coins).boxed().toArray(Integer[]::new);
        Arrays.sort(coinsArray, (a, b) -> b - a);

        int coinCount = 0;
        for (Integer coin : coinsArray) {
            while (amount >= coin) {
                coinCount++;
                amount -= coin;
            }
        }
        return amount == 0 ? coinCount : -1;
    }

    /*
     * Brute Force Method
     * Time: O(2^n)
     * Space: O(n)
     */
    public int coinChange_2(int[] coins, int amount) {
        int result = coinChangeUtil(coins, amount);
        return (result == Integer.MAX_VALUE ? -1 : result);
    }

    private int coinChangeUtil(int[] coins, int amount) {
        if (amount == 0)
            return 0;

        int minCoins = Integer.MAX_VALUE;

        for (int coin : coins) {
            if (amount >= coin) {
                int result = coinChangeUtil(coins, amount - coin);

                if (result != Integer.MAX_VALUE)
                    minCoins = Math.min(minCoins, result + 1);
            }
        }

        return minCoins;
    }

    /*
     * DP Top Down Method
     * Time: O(n * amount)
     * Space: O(amount)
     * Where n is number of coins
     * 
     */
    public int coinChange_3(int[] coins, int amount) {
        int[] cache = new int[amount + 1];
        for (int i = 0; i <= amount; i++)
            cache[i] = -1;

        int result = coinChangeUtil(coins, amount, cache);
        return (result == Integer.MAX_VALUE ? -1 : result);
    }

    private int coinChangeUtil(int[] coins, int amount, int[] cache) {
        if (amount == 0)
            return 0;

        if (cache[amount] == -1) {
            int minCoins = Integer.MAX_VALUE;

            for (int coin : coins) {
                if (amount >= coin) {
                    int result = coinChangeUtil(coins, amount - coin, cache);
                    if (result != Integer.MAX_VALUE)
                        minCoins = Math.min(minCoins, result + 1);
                }
            }
            cache[amount] = minCoins;
        }

        return cache[amount];
    }

    /*
     * DP bottom up method
     * Time: O(amt * n)
     * Space: O(amt)
     */
    public int coinChange(int[] coins, int amount) {
        int[] cache = new int[amount + 1];
        for (int i = 0; i <= amount; i++)
            cache[i] = -1;
        cache[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int minCoins = Integer.MAX_VALUE;
            for (int coin : coins) {
                if (i >= coin) {
                    int result = cache[i - coin];
                    if (result != Integer.MAX_VALUE)
                        minCoins = Math.min(minCoins, result + 1);
                }
            }
            cache[i] = minCoins;
        }
        return (cache[amount] == Integer.MAX_VALUE ? -1 : cache[amount]);
    }
}