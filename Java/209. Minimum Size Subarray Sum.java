class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int min = Integer.MAX_VALUE, sum = 0, start = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            while (start <= i && sum >= target) {
                min = Math.min(min, i - start + 1);
                sum -= nums[start++];
            }
        }

        return min != Integer.MAX_VALUE ? min : 0;
    }
}