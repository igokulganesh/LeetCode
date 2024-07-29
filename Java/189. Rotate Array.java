class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;

        int[] temp = new int[n - k];

        System.arraycopy(nums, 0, temp, 0, n - k);

        for (int i = 0; i < k; i++)
            nums[i] = nums[n - k + i];

        for (int i = k; i < n; i++)
            nums[i] = temp[i - k];
    }
}
/*
 * 0 - [1,2,3,4]
 * 1 - [4,1,2,3]
 * 2 - [3,4,1,2]
 * 3 - [2,3,4,1]
 */