class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        for (int i = 0; i < nums.size(); i++){
            int key = nums[i];
            if (myMap.find(key) != myMap.end()){
                int limit = i - myMap[key];
                if (limit <= k) return true;
            }
            myMap[key] = i;
        }
        return false;
    }
};