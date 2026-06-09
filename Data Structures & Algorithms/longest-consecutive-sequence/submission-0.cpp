class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); i++){
            mySet.insert(nums[i]);
        }
        
        int maxCount = 0;
        for (int num: mySet){
            if (!mySet.count(num-1)){
                int curr = num;
                int count = 1;

                while (mySet.count(curr + 1)){
                    curr++; count++;
                }

                maxCount = count > maxCount ? count: maxCount;
            }
        }

        return maxCount;
    }
};
