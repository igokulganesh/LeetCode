#include <bits/stdc++.h>

using namespace std ; 

int x, y, n, m, zc ;  

int dfs(vector<vector<int>>& g, int i, int j)
{
	if(i < 0 or i == n or j < 0 or j == m or g[i][j] == -1)
		return 0 ; 

	if(g[i][j] == 2 )
	{
		return ((zc == -1) ? 1 : 0) ; 
	}

	g[i][j] = -1 ; 
	zc-- ; 

	int res = dfs(g, i+1, j) + dfs(g, i, j+1) + dfs(g, i-1, j) + dfs(g, i, j-1) ; 

	g[i][j] = 0 ; 
	zc++ ; 

	return res ; 

}

int uniquePathsIII(vector<vector<int>>& g) 
{
	n = g.size() ; 
	m = g[0].size() ;
	zc = 0 ; 
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(!g[i][j])
				zc++ ; 
			else if(g[i][j] == 1)
			{
				x = i ; 
				y = j ;
			}
		}
	}
	return dfs(g, x, y) ; 
}

int main()
{
	vector<vector<int>> v = {
		{1,0,0,0},
		{0,0,0,0},
		{0,0,2,-1}
	}; 

	cout << uniquePathsIII(v) ; 

	return 0 ; 
}	