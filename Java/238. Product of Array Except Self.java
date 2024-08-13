class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] answers = new int[len];

        answers[0] = 1;
        for (int i = 1; i < len; i++)
            answers[i] = answers[i - 1] * nums[i - 1];

        int right = 1;
        for (int i = len - 1; i >= 0; i--) {
            answers[i] = answers[i] * right;
            right *= nums[i];
        }

        return answers;
    }
}

/*
 * 
 * 1 2 3 4
 * 1 1 2 6
 * 
 * 24 12 8 6
 */
