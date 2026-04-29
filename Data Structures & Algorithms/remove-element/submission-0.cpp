class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0 || val > 50) return nums.size();
        int countNums = 0;
        auto read = nums.begin();
        auto write = nums.begin();
        while (read != nums.end()){
            if (*read != val){
                *write++ = *read++;
                countNums++;
            } else read++;
        }
        nums.resize(countNums);
        return countNums;
    }   
};