class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto left = nums.begin();
        auto right = nums.end()-1;
        auto mid = nums.begin();
        while (mid <= right){
            if (*mid == 0){
                swap(*mid++,*left++); // đã duyệt qua trước: 2 --> đẩy rồi | 1,0 --> còn lại
            } else if (*mid == 2){
                swap(*mid,*right--);
            } else {
                mid++;
            }
        }
    }
};