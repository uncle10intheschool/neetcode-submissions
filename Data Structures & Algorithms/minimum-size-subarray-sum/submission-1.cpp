class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int minLen = nums.size()+1;
        int sumSub = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++){
            sumSub += nums[r];
            while (sumSub >= target){
                minLen = min(minLen,r-l+1);
                sumSub -= nums[l++];
            }
        }
        return minLen != nums.size()+1 ? minLen : 0;
    }
};