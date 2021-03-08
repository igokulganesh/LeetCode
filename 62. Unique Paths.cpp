#include<bits/stdc++.h>

using namespace std ; 

int uniquePaths(int i, int j, vector<vector<int>> &dp)
{
	if( i == 0 or j == 0)
		dp[i][j] = 1 ;

	if(dp[i][j] == 0)
	{
		dp[i][j] = uniquePaths(i-1, j, dp) + uniquePaths(i, j-1, dp) ;  
	}

	return dp[i][j] ; 
}

int uniquePaths(int m, int n) 
{
	int res = 0 ; 
	vector<vector<int>> dp(m, vector<int>(n, 0)); 
 	uniquePaths(m-1, n-1, dp) ;
 	return dp[m-1][n-1] ;    
}

int uniquePaths1(int m, int n)
{
	int dp[m][n] ; 

	for(int i = 0 ; i < m ; i++)
		dp[i][0] = 1 ; 

	for(int j = 1 ; j < n ; j++)
		dp[0][j] = 1 ; 

	for(int i = 1 ; i < m ; i++)
	{
		for(int j = 1 ; j < n ; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
		}
	}

	return dp[m-1][n-1] ; 
}

int main()
{
	int m, n ; 
	cin >> m >> n ; 
	cout << uniquePaths1(m, n) ; 
}