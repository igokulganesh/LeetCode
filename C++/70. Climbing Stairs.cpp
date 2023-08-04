// Basic Solution
int climbStairs_native(int n)
{
	if( n == 1 or n == 2 )
		return n ;
	return climbStairs_native(n-1) + climbStairs_native(n-2); 
}

// By using Top down approach
vector<int> dp; 
int climbStairs_dp(int n) 
{
	if(!dp[n])
		dp[n] = climbStairs_dp(n-1) + climbStairs_dp(n-2) ;
	
	return dp[n] ; 
}

int climbStairs(int n)
{
	dp = vector<int>(n+1, 0); 
	dp[1] = 1 ; 
	dp[2] = 2 ;
	return climbStairs_dp(n) ; 
}

// By using bottom up approach
int climbStairs(int n)
{
	dp = vector<int>(n+1, 0); 
	dp[1] = 1 ; 
	dp[2] = 2 ;

	for(int i = 3 ; i <= n ; i++ )
	{
		dp[i] = dp[i-1] + dp[i-2] ; 
	} 
	return dp[n] ; 
}

// Optimizing the Space complexity

int climbStairs(int n)
{
	int a = 0, b = 1, c = 1 ; 

	for(int i = 1 ; i < n ; i++)
	{
		a = b ; 
		b = c ; 
		c = a + b ; 
	}
	return c ;
}