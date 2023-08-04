#include <bits/stdc++.h>
 
using namespace std;

int n ; 
int findWays(string & s, int i, vector<int> & dp)
{
    if(dp[i] == -1)
    {            
        if(s[i] == '0')
            return dp[i] = 0 ;
        
        int ways =  findWays(s, i+1, dp) ; 
        
        if(i < n-1 and (s[i] == '1' or (s[i] == '2' and s[i+1] < '7')))
            ways += findWays(s, i+2, dp); 
            
        dp[i] = ways ; 
    }

    return dp[i] ; 
}

int numDecodings(string s) 
{
    n = s.size(); 
    vector<int> dp(n+1, -1); 
    dp[n] = 1 ; // terimination condition 
    return findWays(s, 0, dp);     
}   