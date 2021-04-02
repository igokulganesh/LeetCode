/*
	Dynamic Programming Approach 
	bottom up approach which takes n*n 
	Timelimit exceeds 
*/

int lengthOfLongestSubstring(string s) 
{
	int n = s.size() ; 

	if(n == 0 or n == 1)
		return n ; 

	vector<vector<bool> > dp(n, vector<bool>(n, 0)); 

	int maxLen = 1 ; 
	for(int i = 0 ; i < n ; i++)
	{
		dp[i][i] = 1 ; 
	}

	for(int i = 0 ; i < n-1 ; i++)
	{
		if(s[i] != s[i+1])
		{
			dp[i][i+1] = 1 ;
			maxLen = 2 ;   
		}
	}

	for(int len = 3 ; len <= n ; len++)
	{
		for(int i = 0 ; i < n-len+1 ; i++)
		{
			int j = i + len - 1; 

			if(s[i] != s[j] and dp[i][j-1] and dp[i+1][j])
			{
				dp[i][j] = 1 ; 
				maxLen = len ; 
			}
		}
	}

	return maxLen ; 
}

/*
	Here is more optimixed solution 
*/

int lengthOfLongestSubstring(string s) 
{
	int n = s.size() ; 

	if(n <= 1)
		return n ; 

	int maxLen = 1 ; 
	int curLen = 1 ; 
	int pi = 0 ; // past index  

	vector<int> Hash(256, 0) ; 
	
	Hash[s[0]]++ ; 

	for(int i = 1 ; i < n ; i++)
	{
		curLen++ ; 

		if(Hash[s[i]])
		{
			while(pi < i)
			{
				Hash[s[pi]] = 0 ; 
				pi++ ;
				curLen-- ; 

				if(s[pi] != s[i] and Hash[s[i]] == 0 )
					break ; 
			}
		}
		Hash[s[i]]++ ;

		maxLen = max(maxLen, curLen) ; 
	}

	return maxLen ; 
}