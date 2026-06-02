class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        auto left = nums.begin();
        auto right = nums.end()-1;

        while (left <= right){
            if (*left == val){
                int temp = *left;
                *left = *right;
                *right = temp;

                right--;
            } else {
                left++;
            }
        }

        return (left - nums.begin());
    }
};