class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 1, count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] == nums[i]) {
                if (count < 2) {
                    nums[k++] = nums[i];
                    count++;
                }
            } else {
                nums[k++] = nums[i];
                count = 1;
            }
        }

        return k;
    }
}

/*
 * 
 * 
 * 0,0,1,1,1,1,2,3,3
 * 0 0 1 1 2 3 3
 * 
 * 
 */