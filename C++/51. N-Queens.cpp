#include <bits/stdc++.h>

using namespace std;

bool isValidMove(vector<string> &board, int row, int col)
{
    // Check column
    for (int i = 0; i < board.size(); i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 and j < board.size(); i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solveNQueens(vector<string> &board, int row, vector<vector<string>> &result)
{
    if (row == board.size())
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < board.size(); col++)
    {
        if (isValidMove(board, row, col))
        {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;

    vector<string> board(n, string(n, '.'));

    solveNQueens(board, 0, result);

    return result;
}
