class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int C = 0;
        int M = 0;
        for (int i = 0; i < nums.size(); i++){
            if (C == 0){
                M = nums[i];
            }
            if (nums[i] == M) C++;
            else C--;
        }
        return M;
    }
};