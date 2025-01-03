
class Solution {

    /*
     * PrefixSum 1
     */
    public int waysToSplitArray_1(int[] nums) {
        long prefixSum[] = new long[nums.length];
        prefixSum[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        long sufixSum[] = new long[nums.length];
        sufixSum[nums.length - 1] = nums[nums.length - 1];

        for (int i = nums.length - 2; i >= 0; i--) {
            sufixSum[i] = sufixSum[i + 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            if (prefixSum[i] >= sufixSum[i + 1]) {
                count++;
            }
        }

        return count;
    }

    /*
     * prefix sum Optimized
     */
    public int waysToSplitArray_2(int[] nums) {
        int n = nums.length;
        long prefixSum[] = new long[n];
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            long leftSum = prefixSum[i];
            long rightSum = prefixSum[n - 1] - prefixSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }

    public int waysToSplitArray(int[] nums) {
        long leftSum = 0, rightSum = 0;

        for (int i = 0; i < nums.length; i++) {
            rightSum += nums[i];
        }

        int count = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
}
