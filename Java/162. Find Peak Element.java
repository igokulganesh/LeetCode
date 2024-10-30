class Solution {
    /*
     * linear search solution
     * Time: O(n)
     * Space: O(1)
     */
    public int findPeakElement_1(int[] nums) {
        int n = nums.length;
        int i;
        for (i = 0; i < n; i++) {
            if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1]))
                break;
        }
        return i;
    }

    /*
     * Finding the Maximum Value and Return will be one of the solution
     * Time: O(n)
     * Space: O(1)
     */
    public int findPeakElement_2(int[] nums) {
        int peak = Integer.MIN_VALUE;
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (peak < nums[i]) {
                peak = nums[i];
                index = i;
            }
        }
        return index;
    }

    /*
     * Binary Search Solution
     * Time: O(log n)
     * Space: O(1)
     */
    public int findPeakElement(int[] nums) {
        int len = nums.length;
        int left = 0, right = len - 1, mid;

        while (left <= right) {
            mid = right + (left - right) / 2;

            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == len - 1 || nums[mid] > nums[mid + 1]))
                return mid;

            // If the current element is smaller than the next element, move to the right
            // half
            if (mid == 0 || nums[mid - 1] < nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
}