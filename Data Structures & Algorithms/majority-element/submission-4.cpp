class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int count = 0; int value = 0;
        for (int num : nums){
            if (count == 0){
                value = num;
            }
            count += (num == value) ? 1 : -1;
        }
        return value;
    }
};