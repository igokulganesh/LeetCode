// Basic Approach
int minCostClimbingStairs(vector<int>& cost, int i)
{
    if(cost.size() <= i)
        return 0 ; 

    return cost[i] + min( minCostClimbingStairs(cost, i+1), minCostClimbingStairs(cost, i+2)); 
}

int minCostClimbingStairs(vector<int>& cost) 
{
    return min(minCostClimbingStairs(cost, 0), minCostClimbingStairs(cost, 1)); 
}

// Top Down DP solution
int minCostClimbingStairs(vector<int>& cost, int i  )
{
    if(cost.size() <= i)
        return 0 ; 

    if(dp[i] == -1)
    {
        dp[i] = cost[i] + min( minCostClimbingStairs(cost, i+1, dp), minCostClimbingStairs(cost, i+2, dp)); 
    }

    return dp[i] ; 
}

int minCostClimbingStairs(vector<int>& cost) 
{
    vector<int> dp(cost.size(), -1);  
    return min(minCostClimbingStairs(cost, 0, dp), minCostClimbingStairs(cost, 1, dp)); 
}

// Bottom Up DP Solution
int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size(); 
    vector<int> dp(n);  
    
    dp[0] = cost[0] ;
    dp[1] = cost[1] ;

    for(int i = 2 ; i < n ; i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]); 
    }

    return min(dp[n-1], dp[n-2]); 
}

// Bottom Up Solution with (Space Optimized)
int minCostClimbingStairs(vector<int> & cost)
{
    int a = cost[0] ;
    int b = cost[1] ; 
    int c ; 

    for(int i = 2 ; i < n ; i++)
    {
        c = cost[i] + min(a, b); 
        a = b ; 
        b = c ;  
    }
    return min(a, b); 
}