class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap(nums.size());
        for (int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if (myMap.find(x) != myMap.end()) return {myMap[x],i};
            myMap.emplace(nums[i],i);
        }
    }
};
