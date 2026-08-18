class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxInRange(n,0);
        for (int i = n-2; i >= 0; i--){
            maxInRange[i] = max(maxInRange[i+1],prices[i+1]);
        }

        int maxPro = 0;
        for (int i = 0; i < n; i++){
            int currPro = -prices[i] + maxInRange[i];
            if (currPro > 0 && currPro > maxPro) maxPro = currPro;
        }
        return maxPro;
    }
};