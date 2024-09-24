
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> result = new ArrayList<>();

        for (int[] vals : intervals) {
            if (result.isEmpty() || result.getLast()[1] < vals[0])
                result.add(vals);
            else
                result.getLast()[1] = Math.max(result.getLast()[1], vals[1]);
        }

        return result.toArray(int[][]::new);
    }
}