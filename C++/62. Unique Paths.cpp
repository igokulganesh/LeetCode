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

/*
	Brute force method 
	Time: O(2^n)
*/
int uniquePaths(int m, int n, int i, int j)
{
	if(i == m-1 and j == n-1)
		return 1 ; 

	if(i == m or j == n)
		return 0 ; 

	return uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);
}

int uniquePaths(int m, int n) 
{
	return uniquePaths(m, n, 0, 0); 
}

/*
	Add Cache to store the intermediate results 
	Top down Approach
	time: O(n^2)
*/

int uniquePaths(int m, int n, int i, int j, vector<vector<int>>& dp)
{
	if(i == m-1 and j == n-1)
		return 1 ; 

	if(i == m or j == n)
		return 0 ; 

	if(dp[i][j] == -1)
		dp[i][j] = uniquePaths(m, n, i+1, j, dp) + uniquePaths(m, n, i, j+1, dp); 
	
	return dp[i][j] ; 
}

int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, -1)); 
	return uniquePaths(m, n, 0, 0, dp); 
}

/*
	Bottom up Approach
	time: O(n^2)
	space: O(n^2)
*/

int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n)); 

	for(int i = 0 ; i < m ; i++)
		dp[i][0] = 1 ; 

	for(int j = 0 ; j < n ; j++)
		dp[0][j] = 1 ; 

	for(int i = 1 ; i < m ; i++)
	{
		for(int j = 1 ; j < n ; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
		}
	}

	return dp.back().back(); 
}

