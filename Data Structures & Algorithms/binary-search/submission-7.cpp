class Solution {
private:
    int bs(int left, int right, vector<int>& nums, int target) {
        if (left > right) return -1;
        int mid = left + (right - left)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return bs(mid+1, right, nums, target);
        else return bs(left,mid-1,nums,target);
    }
public:
    int search(vector<int>& nums, int target) {
        return bs(0,nums.size()-1,nums,target);
    }
};