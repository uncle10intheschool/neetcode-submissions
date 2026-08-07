class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); int count = 0;
        unordered_map<int,int> myMap(n+1); // 0 + prefix[i-1]
        myMap[0]++; int currSum = 0;
        for (int i = 0; i < n; i++){
            currSum += nums[i];
            int preStart = currSum - k;
            if (myMap.count(preStart)) count+= myMap[preStart];
            myMap[currSum]++;
        }
        return count;
    }
};
