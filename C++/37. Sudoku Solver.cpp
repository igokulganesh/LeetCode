#include <vector>

using namespace std;

bool isValidMove(vector<vector<char>> &board, int row, int col, char move)
{
    int b_row = (row / 3) * 3, b_col = (col / 3) * 3;
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == move or board[i][col] == move or board[b_row + i / 3][b_col + i % 3] == move)
            return false;
    }

    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
                continue;

            for (char move = '1'; move <= '9'; move++)
            {
                if (isValidMove(board, i, j, move))
                {
                    board[i][j] = move;
                    if (solveSudoku(board))
                        return true;
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}
