#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-1; j++){
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                for (int k = j+1; k < n; k++){
                    if (k > j+1 && nums[k] == nums[k-1]) continue;
                    if (nums[i] + nums[j] + nums[k] == 0){
                        res.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return res;
    }
};
