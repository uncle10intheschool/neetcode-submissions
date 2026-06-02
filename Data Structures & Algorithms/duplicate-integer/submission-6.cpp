class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        unordered_set<int> mySet(nums.size());
        mySet.insert(nums.front());
        for (int i = 1; i < nums.size(); i++){
            if (mySet.find(nums[i]) != mySet.end()){
                return true;
            }
            mySet.insert(nums[i]);
        }
        return false;
    }
};