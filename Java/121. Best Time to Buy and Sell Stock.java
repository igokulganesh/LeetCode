class Solution {

    public int maxProfit(int[] prices) {
        int profit = 0;
        int bought = Integer.MAX_VALUE;

        for (var price : prices) {
            bought = Integer.min(price, bought);
            profit = Integer.max(price - bought, profit);
        }

        return profit;
    }
}