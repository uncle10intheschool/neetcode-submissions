class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while (mid <= right){
            if (nums[mid] == 0){
                swap(nums[left++],nums[mid++]); 
            } else if (nums[mid] == 1) mid++;
            else {
                swap(nums[right--],nums[mid]);
            } 
        }
    }
};