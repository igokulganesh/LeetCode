#include <bits/stdc++.h>

using namespace std ; 

int uniquePathsWithObstacles(vector<vector<int>>& v, vector<vector<int>>& dp, int i, int j)
{
	if(v[i][j])
		return 0 ; 

	if(i == 0 or j == 0)
		dp[i][j] = 1 ;

	if(dp[i][j] == 0)
	{
		dp[i][j] = uniquePathsWithObstacles(v, dp, i-1, j) + uniquePathsWithObstacles(v, dp, i, j-1) ; 
	} 

	return dp[i][j] ; 
}

int uniquePathsWithObstacles(vector<vector<int>>& v) 
{
	int res = 0 ; 
	vector<vector<int>> dp(v.size(), vector<int>(v[0].size(), 0)); 
 	return uniquePathsWithObstacles(v, dp, dp.size()-1, dp[0].size()-1);     
}

int uniquePathsWithObstacles1(vector<vector<int>>& v)
{
	int n = v.size(), m = v[0].size() ; 
	vector<vector<int>> dp(n, vector<int>(m, 0));

	for(int i = 0 ; i < n ; i++)
	{
		if(v[i][0] == 0)
			dp[i][0] = 1 ; 
		else 
			break ; 
	}

	for(int j = 0 ; j < m ; j++)
	{
		if(v[0][j] == 0)
			dp[0][j] = 1 ; 
		else 
			break ; 
	}

	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			if(v[i][j])
				dp[i][j] = 0 ; 
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
		}
	}

	return dp[n-1][m-1] ; 
}

int main()
{
	vector<vector<int>> v = {
		{0}, {0}
	}; 

	cout << uniquePathsWithObstacles1(v) ; 

	return 0 ; 
}