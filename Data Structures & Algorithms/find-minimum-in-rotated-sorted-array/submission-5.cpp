class Solution {
public:
    int findMin(vector<int> &nums) {
        int pos = -1;
        // O(n)
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] > nums[i]){
                pos = i; break;
            }
        }
        return pos == -1 ? nums[0] : nums[pos];
    }
};