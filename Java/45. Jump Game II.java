class Solution {
    /*
     * Brute Force Approach
     * Time: O(n^2)
     * Space: O(n)
     */
    public int jump(int[] nums, int i) {
        if (i >= nums.length - 1)
            return 0;

        int minJump = Integer.MAX_VALUE - 1000;
        for (int k = 1; k <= nums[i]; k++) {
            minJump = Integer.min(minJump, 1 + jump(nums, i + k));
        }

        return minJump;
    }

    public int jump1(int[] nums) {
        return jump(nums, 0);
    }

    /*
     * Memoization (Top Down Approach DP)
     * Time: O(n^2)
     * Space: O(n)
     */
    public int jump(int[] nums, int[] cache, int i) {
        if (i >= nums.length - 1)
            return 0;

        if (cache[i] == 0) {
            int minJump = Integer.MAX_VALUE - 1000;

            for (int k = 1; k <= nums[i]; k++) {
                minJump = Integer.min(minJump, 1 + jump(nums, cache, i + k));
            }
            cache[i] = minJump;
        }

        return cache[i];
    }

    public int jump2(int[] nums) {
        int[] cache = new int[nums.length];
        return jump(nums, cache, 0);
    }

    /*
     * Tabulation (Bottom up DP Solution)
     * Time: O(n^2)
     * Space: O(n)
     */
    public int jump3(int[] nums) {
        int[] cache = new int[nums.length];

        int minJump;
        for (int i = nums.length - 2; i >= 0; i--) {
            minJump = nums.length + 1;

            for (int k = 1; k <= nums[i]; k++) {
                if (i + k >= nums.length - 1) {
                    minJump = Integer.min(minJump, 1);
                    break;
                }
                minJump = Integer.min(minJump, 1 + cache[i + k]);
            }
            cache[i] = minJump;
        }

        return cache[0];
    }

    /*
     * Greedy
     * Time: O(n)
     * Space: O(1)
     */
    public int jump(int[] nums) {
        if (nums.length <= 1)
            return 0;

        for (int i = 1; i < nums.length; i++)
            nums[i] = Integer.max(nums[i] + i, nums[i - 1]);

        int jumps = 0;
        int i = 0;
        while (i < nums.length - 1) {
            i = nums[i];
            jumps++;
        }

        return jumps;
    }
}