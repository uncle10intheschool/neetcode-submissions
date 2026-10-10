class Solution {
private:
    bool checkMaxSumOfSub(const vector<int>& nums,const int& maxSum /*mid*/, const int& cSub){
        int tmpSum = 0; int tmpCount = 0;
        for (int i = 0; i < nums.size(); i++){
            if (tmpSum + nums[i] > maxSum){
                tmpCount++;
                tmpSum = 0;
            }
            tmpSum += nums[i];
        }
        tmpCount++; // luôn xảy ra tmpSum > 0;
        return tmpCount <= cSub;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = nums[0]; int right = 0;
        for (int i = 0; i < n; i++){
            left = max(left,nums[i]);
            right += nums[i];
        }

        while (left < right){
            int mid = left + (right - left)/2;
            if (checkMaxSumOfSub(nums,mid,k)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};