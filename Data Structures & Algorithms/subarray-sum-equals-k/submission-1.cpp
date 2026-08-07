class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); int count = 0;
        for (int i = 0; i < n; i++){
            int presum = 0;
            for (int j = i; j < n; j++){ // 1 --> n-1
                presum += nums[j];
                if (presum == k) count++;
            }
        }
        return count;
    }
};
