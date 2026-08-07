class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int i = 0; i < prices.size()-1; i++){
            int j = i+1;
            int profit = prices[j] - prices[i];
            if (profit <= 0) continue;
            totalProfit += profit;
        }
        return totalProfit;
    }
};