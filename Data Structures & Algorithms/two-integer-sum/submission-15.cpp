class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map; // a[i]: key | i: data
        for (int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if (map.contains(x)) return {map[x],i}; 
            map.emplace(nums[i],i);
        }
        return {};
    }
};