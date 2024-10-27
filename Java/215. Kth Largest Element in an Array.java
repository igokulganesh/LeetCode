import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> que = new PriorityQueue<>((a, b) -> b - a);

        for (int num : nums)
            que.add(num);

        while (k-- > 1)
            que.poll();

        return que.peek();
    }
}