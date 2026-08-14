class Solution {
private:
    void reverse(vector<int>& nums, int left, int right){
        while (left < right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++; right--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int n = nums.size();
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};