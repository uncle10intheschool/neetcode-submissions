class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for (int i = 0; i < n; i++){
            prefix[i+1] = nums[i] + prefix[i];
        }
        int minLen = n+1;
        for (int i = 0; i < n; i++){
            int left = i, right = n;
            while (left < right){
                int mid = left + (right - left)/2;
                int currSum = prefix[mid+1] - prefix[i];
                if (currSum >= target){
                    right = mid;
                } else {
                    left = mid+1;
                }

                
            }
            
            if (left != n){
                minLen = min(minLen,right-i+1);
            }
        }
        return minLen%(n+1);
    }
};
