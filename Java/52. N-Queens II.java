class Solution {
    int count = 0;

    public int totalNQueens(int n) {
        boolean[][] board = new boolean[n][n];
        totalNQueens(board, n, 0);
        return count;
    }

    private boolean totalNQueens(boolean[][] board, int n, int row) {
        if (row == n) {
            count++;
            return true;
        }

        boolean isSolvable = false;
        for (int col = 0; col < n; col++) {
            if (isValidMove(board, n, row, col)) {
                board[row][col] = true;
                totalNQueens(board, n, row + 1);
                board[row][col] = false;
            }
        }

        return isSolvable;
    }

    private boolean isValidMove(boolean[][] board, int n, int row, int col) {
        for (int i = 0; i < n; i++)
            if (board[i][col])
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j])
                return false;

        return true;
    }
}