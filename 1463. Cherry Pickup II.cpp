#include <bits/stdc++.h>

using namespace std ; 

int row, col ; 
int dp[70][70][70] ; 

int cherryPickup(vector<vector<int>>& grid, int r, int c1, int c2)
{
	if(r == row)
		return 0 ; 

    if( c1 < 0 or c1 == col or c2 < 0 or c2 == col)
		return INT_MIN ; 
    
	if(dp[r][c1][c2] == -1)
	{

		int res = 0 ; 
		res += ((c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2]) ; 

		int temp = 0 ; 
		for(int i = -1 ; i <= 1 ; i++)
			for(int j = -1 ; j <= 1 ; j++)
				temp = max(temp, cherryPickup(grid, r+1, c1+i, c2+j));

		dp[r][c1][c2] = res + temp ; 
	}

	return dp[r][c1][c2] ;
}

int cherryPickup(vector<vector<int>>& grid) 
{
	row = grid.size() ; 
	col = grid[0].size() ; 
	memset(dp, -1, sizeof(dp));
	return max(0, cherryPickup(grid, 0, 0, col-1)) ; 
}