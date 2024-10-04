class Solution {
    int row, col;

    public void solve(char[][] board) {
        row = board.length;
        col = board[0].length;

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                connect(board, i, 0);

            if (board[i][col - 1] == 'O')
                connect(board, i, col - 1);
        }

        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O')
                connect(board, 0, j);

            if (board[row - 1][j] == 'O')
                connect(board, row - 1, j);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == 'G')
                    board[i][j] = 'O';
            }
        }
    }

    private void connect(char[][] board, int i, int j) {
        if (i < 0 || j < 0 || i == row || j == col || board[i][j] != 'O')
            return;

        board[i][j] = 'G';
        connect(board, i + 1, j);
        connect(board, i - 1, j);
        connect(board, i, j + 1);
        connect(board, i, j - 1);
    }
}