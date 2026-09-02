class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int maxP = 0;
        for (int r = 1; r < prices.size(); r++){
            if (prices[l] < prices[r]){
                int currP = prices[r] - prices[l];
                maxP = max(currP, maxP);
            } else l = r;
        }
        return maxP;   
    }
};
