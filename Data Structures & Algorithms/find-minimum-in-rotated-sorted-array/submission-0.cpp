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
        if (pos != -1){
            // O(3n)
            reverse(nums.begin(), nums.begin()+pos);
            reverse(nums.begin()+pos,nums.end());
            reverse(nums.begin(),nums.end());
        }

        return nums[0];
    }
};