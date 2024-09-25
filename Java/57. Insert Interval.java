import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int insert = findInsertionIndex(intervals, newInterval);

        List<int[]> result = new ArrayList<>(Arrays.asList(intervals));
        result.add(insert, newInterval);

        return mergeOverlappingIntervals(result).toArray(int[][]::new);
    }

    private int findInsertionIndex(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0)
            return 0;

        int left = 0, right = intervals.length - 1;
        int mid, index = intervals.length;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (intervals[mid][0] > newInterval[0]) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return index;
    }

    private List<int[]> mergeOverlappingIntervals(List<int[]> intervals) {
        List<int[]> result = new ArrayList<>();

        for (int[] vals : intervals) {
            if (result.isEmpty() || result.getLast()[1] < vals[0]) {
                result.add(vals);
            } else {
                result.getLast()[1] = Math.max(result.getLast()[1], vals[1]);
            }
        }

        return result;
    }
}