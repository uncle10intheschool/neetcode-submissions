class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n); leftMax[0] = nums[0];
        vector<int> rightMax(n); rightMax[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            if (i%k == 0){ // milestone
                leftMax[i] = nums[i];
            } else leftMax[i] = max(leftMax[i-1],nums[i]);

            if ((n-i-1)%k == 0){ // milestone
                rightMax[n-i-1] = nums[n-i-1];
            } else rightMax[n-i-1] = max(rightMax[n-i],nums[n-i-1]);
        }
        vector<int> res;
        for (int i = 0; i <= n - k; i++){
            int maxVal = max(rightMax[i],leftMax[i+k-1]);
            res.push_back(maxVal);
        }

        return res;
    }
};