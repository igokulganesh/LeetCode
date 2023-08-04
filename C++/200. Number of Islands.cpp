/* here I used DFS method to remove the visited island 
   we can also use BFS (queue) to achieve same 
*/

int r, c ; 

void numIslands(vector<vector<char>>& grid, int i, int j) // DFS 
{
	if(i == r or j == c or i < 0 or j < 0 or grid[i][j] == '0')
		return ; 

	grid[i][j] = '0' ;

	numIslands(grid, i+1, j) ; 
	numIslands(grid, i-1, j) ;
	numIslands(grid, i, j+1) ;
	numIslands(grid, i, j-1) ;  
}

int numIslands(vector<vector<char>>& grid) 
{
	r = grid.size() ; 
	c = grid[0].size() ; 

	int res = 0 ; 

	for(int i = 0 ; i < r ; i++)
	{
		for(int j = 0 ; j < c ; j++)
		{
			if(grid[i][j] == '1')
			{
				numIslands(grid, i, j); 
				res++ ; 
			}
		}
	}

	return res ; 
}	