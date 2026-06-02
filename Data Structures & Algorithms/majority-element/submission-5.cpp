class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int count = 0;
        int king = 0; // not count yet
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                king = nums[i];
            }
            if (nums[i] == king) count++;
            else count--;
        }
        return king;
    }
};