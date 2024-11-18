import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    /*
     * Brute-force-method
     * Time: O(n^2)
     */
    public List<List<Integer>> kSmallestPairs_1(int[] nums1, int[] nums2, int k) {
        PriorityQueue<Integer[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0] + a[1], b[0] + b[1]));

        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                pq.add(new Integer[] { nums1[i], nums2[j] });
            }
        }

        List<List<Integer>> result = new ArrayList<>();

        while (k-- > 0) {
            result.add(Arrays.asList(pq.poll()));
        }

        return result;
    }

    /*
     * Brute-force-method with little optimization
     * Time: O(n^2)
     */
    public List<List<Integer>> kSmallestPairs_2(int[] num1, int[] num2, int k) {
        PriorityQueue<Integer[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0] + a[1], b[0] + b[1]));
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < num1.length; i++) {
            for (int j = 0; j < num2.length; j++) {
                if (pq.size() < k)
                    pq.add(new Integer[] { num1[i], num2[j] });
                else if (pq.peek()[0] + pq.peek()[1] > num1[i] + num2[j]) {
                    pq.poll();
                    pq.add(new Integer[] { num1[i], num2[j] });
                }
            }
        }

        while (k-- > 0)
            result.add(Arrays.asList(pq.poll()));

        return result;
    }

    /*
     * Optimized Solution
     */
    public List<List<Integer>> kSmallestPairs(int[] num1, int[] num2, int k) {
        PriorityQueue<Integer[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0] + a[1], b[0] + b[1]));
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < num1.length && i < k; i++)
            pq.add(new Integer[] { num1[i], num2[0], 0 });

        while (k-- > 0 && !pq.isEmpty()) {
            Integer[] cur = pq.poll();
            result.add(Arrays.asList(cur[0], cur[1]));

            if (cur[2] < num2.length) {
                pq.add(new Integer[] { cur[0], num2[cur[2] + 1], cur[2] + 1 });
            }
        }

        return result;
    }

}