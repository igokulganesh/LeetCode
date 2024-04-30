#include <bits/stdc++.h>

using namespace std;

// Basic Solution
int climbStairs_native(int n)
{
	if (n == 1 or n == 2)
		return n;
	return climbStairs_native(n - 1) + climbStairs_native(n - 2);
}

// By using Top down approach
int climbStairs(int n, vector<int> &dp)
{
	if (n == 1 or n == 2)
		return n;

	if (dp[n] == 0)
		dp[n] = climbStairs(n - 1) + climbStairs(n - 2);

	return dp[n];
}

int climbStairs(int n)
{
	vector<int> dp(n + 1, 0);
	return climbStairs(n, dp);
}

// By using bottom up approach
int climbStairs(int n)
{
	if (n == 1 or n == 2)
		return n;

	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}

// Optimizing the Space complexity
int climbStairs(int n)
{
	if (n == 1 or n == 2)
		return n;

	int prev1 = 1, prev2 = 2;
	int cur;

	for (int i = 3; i <= n; i++)
	{
		cur = prev1 + prev2;
		prev1 = prev2;
		prev2 = cur;
	}
	return cur;
}

int climbStairs(int n)
{
	int a = 0, b = 1, c = 1;

	for (int i = 1; i < n; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}