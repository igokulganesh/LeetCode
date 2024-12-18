class Solution {
    public boolean exist(char[][] board, String word) {
        char[] wordArr = word.toCharArray();

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == wordArr[0] && exist(board, wordArr, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    private boolean exist(char[][] board, char[] word, int i, int j, int cur) {
        if (word.length == cur)
            return true;

        if (i == board.length || j == board[0].length || i < 0 || j < 0 || board[i][j] != word[cur])
            return false;

        board[i][j] = '*';

        boolean result = exist(board, word, i + 1, j, cur + 1) || exist(board, word, i, j + 1, cur + 1)
                || exist(board, word, i - 1, j, cur + 1) || exist(board, word, i, j - 1, cur + 1);

        board[i][j] = word[cur];

        return result;
    }

}