#include <bits/stdc++.h>

using namespace std;

/*
	Sliding Window Technique
	Time : O(n)
	space : Constant
*/
int lengthOfLongestSubstring(string s)
{
	vector<bool> characters(256, false);
	int longest_str = 0;
	int start = 0;

	for (int i = 0; i < s.size(); i++)
	{
		while (i != start and characters[s[i]])
			characters[s[start++]] = false;

		characters[s[i]] = true;

		longest_str = max(longest_str, i - start + 1);
	}

	return longest_str;
}

/*
	Dynamic Programming Approach
	bottom up approach which takes n*n
	Timelimit exceeds
*/
int lengthOfLongestSubstring(string s)
{
	int n = s.size();

	if (n == 0 or n == 1)
		return n;

	vector<vector<bool>> dp(n, vector<bool>(n, 0));

	int maxLen = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			dp[i][i + 1] = 1;
			maxLen = 2;
		}
	}

	for (int len = 3; len <= n; len++)
	{
		for (int i = 0; i < n - len + 1; i++)
		{
			int j = i + len - 1;

			if (s[i] != s[j] and dp[i][j - 1] and dp[i + 1][j])
			{
				dp[i][j] = 1;
				maxLen = len;
			}
		}
	}

	return maxLen;
}
/*
  G O K U L
G 1 1
O   1 1
K     1 1
U       1 1
L 		  1
*/