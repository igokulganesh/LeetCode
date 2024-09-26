
import java.util.Arrays;

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (p1, p2) -> Integer.compare(p1[1], p2[1]));

        int minArrow = 1;
        int prev = points[0][1];

        for (int i = 1; i < points.length; i++) {
            if (prev < points[i][0]) {
                prev = points[i][1];
                minArrow++;
            }
        }

        return minArrow;
    }
}