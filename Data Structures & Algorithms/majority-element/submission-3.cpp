class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int count = 1; int value = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != value){
                count--;
                if (count < 0){
                    value = nums[i];
                    count = 1;
                }
            } else { // a[i] == value
                count++;
            }
        }
        return value;
    }
};