
string longestPalindrome(string s) 
{
	int n = s.size() ; 
 	vector<vector<bool>> dp(n, vector<bool>(n, 0)); 

 	int maxLen = 1 ;
 	int start = 0 ; // starting of palindrome  

 	for(int i = 0 ; i < n ; i++)
 		dp[i][i] = 1 ; 
 	
 	for(int i = 0 ; i < n-1 ; i++)
 	{
 		if(s[i] == s[i+1])
 		{
 			dp[i][i+1] = 1 ; 
 			maxLen = 2 ; 
 			start = i ; 
 		}
 	}

 	for(int len = 3 ; len <= n ; len++)
 	{
 		for(int i = 0 ; i < n-len+1 ; i++)
 		{
 			int j = i + len - 1 ; 

 			if(s[i] == s[j] and dp[i+1][j-1])
 			{
 				dp[i][j] = 1 ; 
 				maxLen = len ; 
 				start = i ; 
 			}
 		}
 	}

 	return s.substr(start, maxLen);  
}

//	Time compelexity O(n^2) 