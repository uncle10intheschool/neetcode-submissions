class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++){
            int currPro = prices[i] - minPrice;
            if (currPro < 0) minPrice = prices[i];
            else if (currPro > 0){
                if (currPro > maxPro) maxPro = currPro;
            }
        }
        return maxPro;
    }
};