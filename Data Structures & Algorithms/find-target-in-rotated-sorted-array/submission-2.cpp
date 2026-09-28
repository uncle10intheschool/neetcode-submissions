class Solution {
private:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] < nums[right]){
                right = mid;
            } else left = mid + 1;
        }
        return right;
    }

    int bs(int left, int right, vector<int> & nums, int target){
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target){
                left = mid + 1;
            } else right = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = findMin(nums);
        int left = 0, right = start-1;
        if (nums[start] <= target && target <= nums[n-1]){
            left = start, right = n-1;
        }
        return bs(left,right,nums,target);
    }
};