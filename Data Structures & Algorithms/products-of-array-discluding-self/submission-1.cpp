class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> bef(n,1); vector<int> aft(n,1);
        for (int i = 1; i < n; i++){
            bef[i] = bef[i-1]*nums[i-1];
            aft[n-1-i] = aft[n-i]*nums[n-i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++){
            res[i] = bef[i]*aft[i];
        }
        return res;
    }
};
