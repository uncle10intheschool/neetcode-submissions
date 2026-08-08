class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int& x : nums){
            if (x < 0) x = 0;
        }

        for (int i = 0; i < n; i++){
            int val = abs(nums[i]);
            if (val >= 1 && val <= n){
                if (nums[val-1] > 0) nums[val-1] *= -1;
                else { // full 0 or !0
                    nums[val-1] = -(n+1);
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (nums[i] >= 0) return i+1;
        }

        return n+1;
    }
};