class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++){
            int currPro = prices[i] - minPrice;
            maxPro = max(maxPro,currPro);
            minPrice = min(minPrice,prices[i]);
        }
        return maxPro;
    }
};