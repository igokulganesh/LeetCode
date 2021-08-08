bool isValidMove(vector<vector<char>>& b, int row, int col, char k)
{
    int b_row = (row / 3) * 3, b_col = (col / 3) * 3;
    for(int i = 0 ; i < 9 ; i++)
    {
        if(b[row][i] == k or b[i][col] == k or b[b_row + i / 3][b_col + i % 3] == k)
            return false ; 
    }
    return true ; 
}

bool solveSudoku(vector<vector<char>>& board) 
{
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            if(board[i][j] != '.')
                continue ; 

            for(char k = '1' ; k <= '9' ; k++ ) 
            {
                if(isValidMove(board, i, j, k))
                {
                    board[i][j] = k ; 
                    if(solveSudoku(board))
                        return true ;
                    board[i][j] = '.' ; 
                }
            }
            return false ; 
        }
    }
    return true ; 
}