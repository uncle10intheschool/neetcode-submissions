class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mySet(nums.begin(),nums.end());
        int maxCount = 0;
        for (int num: mySet){
            if (mySet.find(num-1) == mySet.end()){
                int count = 1;
                while (mySet.find(num+1) != mySet.end()){
                    count++;
                    num++;
                }
                maxCount = max(count,maxCount);
            }
        }
        return maxCount;
    }
};