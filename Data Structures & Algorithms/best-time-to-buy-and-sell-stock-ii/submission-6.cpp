class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int NotBuyAfter = 0; // dp[i+1][0]
        int BuyAfter = 0; // dp[i+1][1]
        int NotBuyCurr = 0; // save the notbuyafter first
        int BuyCurr = 0; // save the buyafter first

        for (int i = n-1; i >= 0; i--){
            NotBuyCurr = max(NotBuyAfter,-prices[i] + BuyAfter);
            BuyCurr = max(BuyAfter, prices[i] + NotBuyAfter);

            NotBuyAfter = NotBuyCurr;
            BuyAfter = BuyCurr;
        }
        return NotBuyAfter;
    }
};