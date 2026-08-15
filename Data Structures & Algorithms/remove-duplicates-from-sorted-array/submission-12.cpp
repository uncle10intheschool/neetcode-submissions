class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1, read = 1;
        while (read < nums.size()){
            if (nums[read] != nums[read-1]){
                nums[write] = nums[read];
                write++;
            }
            read++;
        }
        return write;
    }
};