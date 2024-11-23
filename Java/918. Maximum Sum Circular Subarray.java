class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int curMax = 0;
        int maxSum = nums[0];

        int curMin = 0;
        int minSum = nums[0];

        int totalSum = 0;

        for (int num : nums) {
            curMax += num;
            maxSum = Math.max(maxSum, curMax);
            curMax = Math.max(curMax, 0);

            curMin += num;
            minSum = Math.min(minSum, curMin);
            curMin = Math.min(curMin, 0);

            totalSum += num;
        }

        // if all num are negative
        if (totalSum == minSum)
            return maxSum;

        return Math.max(maxSum, totalSum - minSum);
    }
}