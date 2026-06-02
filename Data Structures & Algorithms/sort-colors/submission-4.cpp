class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto left = nums.begin();
        auto right = nums.end()-1;
        auto mid = nums.begin();

        while (mid <= right){
            if (*mid == 2){
                swap(*mid,*right--);
            } else if (*mid == 1){
                mid++;
            } else { // == 0
                swap(*mid++,*left++);
            }
        }
    }
};