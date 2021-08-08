bool isValidMove(vector<string>& board, int n, int row, int col)
{
    // Check column
    for(int i = 0 ; i < n ; i++) 
        if(board[i][col] == 'Q')
            return false ;
    
    for(int i = row, j = col ; i >= 0 and j >= 0 ; i--, j--)
        if(board[i][j] == 'Q')
            return false ; 

    for(int i = row, j = col ; i >= 0 and j < n ; i--, j++)
        if(board[i][j] == 'Q')
            return false ; 
        
    return true ; 
}

void solve(vector<vector<string>>& res, vector<string>& board, int n, int row)
{
    if(row == board.size())
    {
        res.push_back(board);
        return ; 
    }
    
    for(int col = 0 ; col < n ; col++)
    {
        if(isValidMove(board, n, row, col))
        {
            board[row][col] = 'Q' ;
            solve(res, board, n, row+1);
            board[row][col] = '.' ; 
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> res ;

    vector<string> board(n, string(n, '.')) ;    

    solve(res, board, n, 0);

    return res ;
}