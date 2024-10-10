import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>(n);
        char[][] board = new char[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = '.';

        solveNQueens(n, result, board, 0);

        return result;
    }

    private boolean solveNQueens(int n, List<List<String>> result, char[][] board, int row) {
        if (row == n) {
            result.add(constructBoard(board));
            return false;
        }

        boolean isSolvable = false;

        for (int col = 0; col < n; col++) {
            if (isValidMove(board, n, row, col)) {
                board[row][col] = 'Q';
                if (solveNQueens(n, result, board, row + 1))
                    isSolvable = true;
                board[row][col] = '.';
            }
        }

        return isSolvable;
    }

    private boolean isValidMove(char[][] board, int n, int row, int col) {
        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    private List<String> constructBoard(char[][] board) {
        List<String> newBoard = new ArrayList<>();

        for (char[] cur : board)
            newBoard.add(new String(cur));

        return newBoard;
    }
}