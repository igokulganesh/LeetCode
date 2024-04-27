#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = prices[0], max_profit = 0;

    for (auto price : prices)
    {
        max_profit = max(max_profit, price - buy);
        buy = min(buy, price);
    }

    return max_profit;
}