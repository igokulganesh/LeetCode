int maxProfit(vector<int>& prices) 
{
    int profit = 0, stock = prices[0] ; 

    for(int i = 1 ; i < prices.size() ; i++)
    {
        profit = max(profit, prices[i]-stock);  
        stock = min(stock, prices[i]); 
    }

    return profit ; 
}