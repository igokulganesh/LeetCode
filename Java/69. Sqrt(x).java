class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x, m;

        while (l <= r) {
            m = l + (r - l) / 2;
            if ((long) m * m > (long) x)
                r = m - 1;
            else if ((long) m * m < (long) x)
                l = m + 1;
            else
                return m;
        }
        return r;
    }
}