
import java.util.HashSet;
import java.util.Set;

class Solution {
    /*
     * Time-Limit-Exceed
     */
    public int longestConsecutive_usingSet(int[] nums) {
        int longest = 0, cur;

        Set<Integer> set = new HashSet<>();

        for (Integer num : nums)
            set.add(num);

        for (Integer num : nums) {
            cur = 1;
            while (set.contains(num - 1)) {
                cur++;
                num--;
            }
            longest = Math.max(cur, longest);
        }

        return longest;
    }

    public int longestConsecutive(int[] nums) {
        int longest = 0, cur;

        Set<Integer> set = new HashSet<>();

        for (Integer num : nums)
            set.add(num);

        for (Integer val : set) {
            if (set.contains(val - 1))
                continue;

            cur = 1;
            while (set.contains(++val))
                cur++;

            longest = Math.max(cur, longest);
        }

        return longest;
    }
}
