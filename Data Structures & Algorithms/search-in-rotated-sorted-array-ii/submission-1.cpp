class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[left]) left++; 
            // mid ko phải target --> left cũng ko bằng 
            else if (nums[left] < nums[mid]){ // left sorted
                if (target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                } else left = mid + 1;
            } else { // right sorted
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else right = mid - 1;
            }
        }
        return false;
    }
};