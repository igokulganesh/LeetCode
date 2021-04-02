#include <bits/stdc++.h>

using namespace std ; 

int n , m ; 

bool isMatch(string & s, string & p, int i, int j, char c = 0)
{
	if(i == n and j == m)
		return true ; 

	if(i < n and j < m)
	{
		if(s[i] == p[j] or p[j] == '.')
			return isMatch(s, p, i+1, j+1); 

		if(p[j] == '*')
		{
			if(s[i] == p[j-1] or p[j-1] == '.')
				return isMatch(s, p, i+1, j) ;
			else // zero occurence of characters 
				return isMatch(s, p, i, j+2); 
		}
	}
	return false ; 
}

bool isMatch(string & s, string & p) 
{
	vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));

	dp[0][0] = true ; 

	for(int j = 1 ; j <= p.size() ; j++)
	{
		if(p[j-1] == '*')
			dp[0][j] = dp[0][j-2] ; 
	}

	for(int i = 1 ; i <= s.size() ; i++)
	{
		for(int j = 1 ; j <= p.size() ; j++)
		{
			if(s[i-1] == p[j-1] or p[j-1] == '.')
				dp[i][j] = dp[i-1][j-1] ; 
			else if(p[j-1] == '*')
			{
				if(dp[i][j-2]) // check zero occurence 
					dp[i][j] = true ; 
				else if(s[i-1] == p[j-2] or p[j-2] == '.')
					dp[i][j] = dp[i-1][j]; 
			}
			else
				dp[i][j] = false ; 
		}
	}

	return dp.back().back() ; 
}

int main()
{
	string s, p ; 

	cin >> s >> p ; 

	cout << (isMatch(s, p) ? 'true' : 'false' ) << endl ;  

	return 0 ; 
}