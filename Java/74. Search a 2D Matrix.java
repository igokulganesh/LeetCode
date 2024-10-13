class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int row = 0;

        while (row < m) {
            if (matrix[row][n - 1] >= target)
                break;
            row++;
        }

        if (row < m) {
            int left = 0, right = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;

                if (matrix[row][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
}