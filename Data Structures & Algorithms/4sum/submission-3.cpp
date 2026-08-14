using ll = long long;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int a = 0; a < n-3; a++){
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (int b = a+1; b < n-2; b++){
                if (b > a+1 && nums[b] == nums[b-1]) continue;
                ll newTarget = (ll)target - nums[a] - nums[b];
                
                int c = b+1, d = n-1;
                while (c < d){
                    ll sum = (ll)nums[c] + nums[d];
                    if (sum == newTarget){
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++; d--;

                        while (c < d && nums[c] == nums[c-1]) c++;
                        while (c < d && nums[d] == nums[d+1]) d--;
                    } else if (sum < newTarget) c++;
                    else d--;
                }
            }
        }
        return res;
    }
};