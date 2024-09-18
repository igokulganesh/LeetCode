class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i) || !isValidCol(board, i) || !isValidBox(board, i))
                return false;
        }
        return true;
    }

    private boolean isValidBox(char[][] board, int box) {
        boolean seen[] = new boolean[9];
        int row = (box / 3) * 3;
        int col = (box % 3) * 3;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] != '.') {
                    if (seen[board[i][j] - '1']) {
                        return false;
                    }
                    seen[board[i][j] - '1'] = true;
                }
            }
        }

        return true;
    }

    private boolean isValidCol(char[][] board, int col) {
        boolean seen[] = new boolean[9];

        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (seen[board[i][col] - '1'])
                    return false;
                seen[board[i][col] - '1'] = true;
            }
        }

        return true;
    }

    private boolean isValidRow(char[][] board, int row) {
        boolean seen[] = new boolean[9];

        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                if (seen[board[row][i] - '1'])
                    return false;
                seen[board[row][i] - '1'] = true;
            }
        }
        return true;
    }
}

/*
 * 0 - 0 0
 * 1 - 0 3
 * 2 - 0 6
 * 3 - 1 0
 * 4 - 1 3
 * 5 - 1 6
 * 6 - 2 0
 * 7 - 2 3
 * 8 - 2 3
 * 
 * Row = i / 3
 * Column = i * 3 % 9
 */