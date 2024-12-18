import java.util.Stack;

class Solution {

    /*
     * Brute-Force Method
     * Time: O(n^2)
     * Space: O(1)
     */
    public int[] finalPrices_1(int[] prices) {

        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                if (prices[i] >= prices[j]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }

    /*
     * Monotonic Stack
     * Time: O(n)
     * Space: O(n)
     */
    public int[] finalPrices(int[] prices) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < prices.length; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] >= prices[i]) {
                prices[stack.pop()] -= prices[i];
            }

            stack.add(i);
        }

        return prices;
    }
}