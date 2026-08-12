class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> choices(2,vector<int>(prices.size(),-1));
        return rec(prices,0,false,choices);
    }
private:
    int rec(vector<int>& prices, int i, bool buy, vector<vector<int>>& choices){
        if (i == prices.size()) return 0;

        if (choices[buy][i] != -1) return choices[buy][i];
        
        int res = rec(prices,i+1,buy,choices);

        if (buy){
            res = max(res, prices[i] + rec(prices,i+1,false,choices));
        } else res = max(res, -prices[i] + rec(prices,i+1,true,choices));
        choices[buy][i] = res;
        return res;
    }
};