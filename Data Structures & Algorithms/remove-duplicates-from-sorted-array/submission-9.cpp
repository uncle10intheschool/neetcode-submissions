class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto read = nums.begin();
        auto write = nums.begin();
        while (read != nums.end()){
            *write = *read;
            while (read != nums.end()&& *read == *write) read++;
            write++; 
        }
        return write - nums.begin();
    }
};