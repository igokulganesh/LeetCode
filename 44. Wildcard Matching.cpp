#include <bits/stdc++.h>

using namespace std ; 

bool isMatch(string & s, string & p) 
{
	bool flag = true ; 

	for(int i = 0 ; i < p.size() ; i++)
	{
		if(p[i] == '*')
		{
			if(flag)
				flag = false ; 
			else
				p.erase(i--, 1); 

		}
		else
			flag = true ; 
	}

	// cout << p << endl ; 

	vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));

	dp[0][0] = true ; 

	if(p[0] == '*')
		dp[0][1] = true ; 

	for(int i = 1 ; i < dp.size() ; i++)
	{
		for(int j = 1 ; j < dp[0].size() ; j++)
		{
			if(s[i-1] == p[j-1] or p[j-1] == '?')
				dp[i][j] = dp[i-1][j-1] ; 
			else if(p[j-1] == '*')
				dp[i][j] = dp[i-1][j] or dp[i][j-1] ; 
		}
	}

	return dp.back().back() ;
}

/*bool isMatch(string & s, string & p, int i, int j)
{
	if(s.size() == i and p.size() == j)
		return true ; 

	if(s.size() == i or p.size() == j)
		return false ; 

	if(p[j] == '*')
		return (isMatch(s, p, i+1, j) or isMatch(s, p, i, j+1)); 

	if(p[j] == '?' or s[i] == p[j])
		return isMatch(s, p, i+1, j+1);

	return false ; 
}

bool isMatch(string & s, string & p)
{
	return isMatch(s, p, 0, 0); 
}*/

int main()
{
	string s, p ; 

	cin >> s >> p ; 

	cout << (isMatch(s, p) ? "true" : "false" ) << endl ;  

	return 0 ; 
}