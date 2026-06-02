class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map(nums.size()); // a[i]: key | i: data
        for (int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if (map.count(x)) return {map[x],i}; 
            else {
                map.emplace(nums[i],i);
            }
        }
        return {-1,-1};
    }
};
