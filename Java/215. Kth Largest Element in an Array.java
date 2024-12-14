import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int findKthLargest_sort(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }

    public int findKthLargest_max(int[] nums, int k) {
        PriorityQueue<Integer> que = new PriorityQueue<>((a, b) -> b - a);

        for (int num : nums)
            que.add(num);

        while (k-- > 1)
            que.poll();

        return que.peek();
    }

    public int findKthLargest_min(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i < k; i++)
            minHeap.add(nums[i]);

        for (int i = k; i < nums.length; i++) {
            if (minHeap.peek() < nums[i]) {
                minHeap.poll();
                minHeap.add(nums[i]);
            }
        }

        return minHeap.peek();
    }

    /* same as above */
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : nums) {
            if (minHeap.size() == k && minHeap.peek() < num)
                minHeap.poll();

            if (minHeap.size() < k)
                minHeap.add(num);
        }

        return minHeap.peek();
    }
}
