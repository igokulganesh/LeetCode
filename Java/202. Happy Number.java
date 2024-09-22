
import java.util.HashSet;
import java.util.Set;

class Solution {
    /*
     * Time: O(n)
     * Space: O(n)
     */
    public boolean isHappy_usingSet(int n) {
        Set<Integer> set = new HashSet<>();

        while (n != 1) {
            n = findSquare(n);

            if (set.contains(n))
                return false;

            set.add(n);
        }

        return true;
    }

    private int findSquare(int n) {
        int result = 0;

        while (n > 0) {
            result += (n % 10 * n % 10);
            n /= 10;
        }

        return result;
    }

    public boolean isHappy(int n) {
        int fast = n, slow = n;

        do {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        } while (slow != fast);

        return slow == 1;
    }
}