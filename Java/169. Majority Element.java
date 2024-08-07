import java.util.Arrays;
import java.util.HashMap;

/* 
 * Time: O(nlogn)
 * space: O(1)
 */
class Solution {

    public int majorityElement_1(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }

    /*
     * HashMap Solution
     * Time: O(n)
     * space: O(n)
     */

    public int majorityElement_2(int[] nums) {

        var map = new HashMap<Integer, Integer>();
        int major = 0;
        int count = 0;

        for (var ele : nums) {
            map.put(ele, map.getOrDefault(ele, 0) + 1);

            if (map.get(ele) > count) {
                major = ele;
                count = map.get(ele);
            }
        }

        return major;
    }

    /*
     * Optimized Approach
     * moor's voting Alg
     * 
     * Time: O(n)
     * space: O(1)
     */
    public int majorityElement_3(int[] nums) {
        int count = 0;
        int major = 0;

        for (int num : nums) {
            if (count == 0)
                major = num;

            if (major == num)
                count++;
            else
                count--;
        }

        return major;
    }
}
