import java.util.PriorityQueue;

class Solution {
    /*
     * Min Heap
     * Time: O(k * (n log n))
     * Space: O(n)
     */
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Integer[]> minHeap = new PriorityQueue<>((a, b) -> {
            int comp = Integer.compare(a[0], b[0]);
            if (comp == 0)
                comp = Integer.compare(a[1], b[1]);
            return comp;
        });

        for (int i = 0; i < nums.length; i++)
            minHeap.add(new Integer[] { nums[i], i });

        while (k-- > 0) {
            Integer[] min = minHeap.poll();
            min[0] *= multiplier;
            minHeap.add(min);
        }

        minHeap.forEach(ele -> nums[ele[1]] = ele[0]);

        return nums;
    }

    /*
     * Brute-force-Approach (Still Best)
     * Time: O(k * n)
     * Space: O(1)
     */
    public int getMinIndex(int[] nums) {
        int result = 0, min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < min) {
                result = i;
                min = nums[i];
            }
        }
        return result;
    }

    public int[] getFinalState_1(int[] nums, int k, int multiplier) {
        while (k-- > 0) {
            nums[getMinIndex(nums)] *= multiplier;
        }
        return nums;
    }
}