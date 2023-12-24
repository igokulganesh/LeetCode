pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut profit = 0;
    let mut buy = prices[0];

    for i in 1..prices.len() {
        if prices[i] > buy {
            profit = std::cmp::max(profit, prices[i] - buy);
        } else {
            buy = prices[i];
        }
    }

    profit
}
