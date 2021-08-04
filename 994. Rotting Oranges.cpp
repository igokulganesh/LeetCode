int orangesRotting(vector<vector<int>>& grid) 
{
    int m = grid.size(); 
    int n = grid[0].size(); 
    queue<pair<int, int>> q ; 
    int time = 0 ; 
    int fresh = 0 ; 

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(grid[i][j] == 2)
                q.push({i, j}); 
            else if(grid[i][j] == 1)
                fresh++ ; 
        }
    }    

    int x, y, len ;   

    while(!q.empty())
    {
        len = q.size();
        while(len--)
        {

            x = q.front().first ; 
            y = q.front().second;
            q.pop();

            if(x+1 < m and grid[x+1][y] == 1)
            {
                q.push({x+1, y}); 
                grid[x+1][y] = 2 ;
                fresh-- ; 
            }

            if(x-1 >= 0 and grid[x-1][y] == 1)
            {
                q.push({x-1, y}); 
                grid[x-1][y] = 2 ;
                fresh-- ;
            }

            if(y+1 < n and grid[x][y+1] == 1)
            {
                q.push({x, y+1}); 
                grid[x][y+1] = 2 ;
                fresh-- ; 
            }

            if(y-1 >= 0  and grid[x][y-1] == 1)
            {
                q.push({x, y-1}); 
                grid[x][y-1] = 2 ;
                fresh-- ; 
            }
        }  

        if(!q.empty())
            time++ ;  
    }

    return (fresh == 0) ? time : -1  ; 
}