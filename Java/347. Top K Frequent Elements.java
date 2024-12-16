import java.util.Map;
import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public int[] topKFrequent_1(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);

        PriorityQueue<Integer[]> maxHeap = new PriorityQueue<>(((a, b) -> Integer.compare(b[1], a[1])));
        for (int num : map.keySet())
            maxHeap.add(new Integer[] { num, map.get(num) });

        int result[] = new int[k];
        for (int i = 0; i < k; i++)
            result[i] = maxHeap.poll()[0];

        return result;
    }

    public int[] topKFrequent_2(int[] nums, int k) {
        if (k == nums.length)
            return nums;

        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);

        PriorityQueue<Integer> minHeap = new PriorityQueue<>(((a, b) -> Integer.compare(map.get(a), map.get(b))));
        for (int num : map.keySet()) {
            minHeap.add(num);
            if (minHeap.size() > k)
                minHeap.poll();
        }

        int result[] = new int[k];
        for (int i = k - 1; i >= 0; i--)
            result[i] = minHeap.poll();

        return result;
    }

    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);

        PriorityQueue<Integer[]> minHeap = new PriorityQueue<>(((a, b) -> Integer.compare(a[1], b[1])));
        for (int num : map.keySet()) {
            minHeap.add(new Integer[] { num, map.get(num) });
            if (minHeap.size() > k)
                minHeap.poll();
        }

        int result[] = new int[k];
        for (int i = k - 1; i >= 0; i--)
            result[i] = minHeap.poll()[0];

        return result;
    }
}