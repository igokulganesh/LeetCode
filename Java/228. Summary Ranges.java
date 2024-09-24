
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();

        int len = nums.length;
        int start, end;

        for (int i = 0; i < len; i++) {
            start = end = nums[i];
            while (i + 1 < len && end + 1 == nums[i + 1]) {
                i++;
                end = nums[i];
            }

            if (start == end)
                result.add(String.valueOf(start));
            else
                result.add(String.valueOf(start) + "->" + String.valueOf(end));
        }

        return result;
    }
}