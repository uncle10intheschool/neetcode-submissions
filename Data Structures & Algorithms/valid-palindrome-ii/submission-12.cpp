class Solution {
private:
    bool isPalindrome(auto left, auto right, string s){
        while (left < right){
            if (*left != *right) return false;
            left++; right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end()-1;
        while (left < right){
            if (*left != *right){
                return isPalindrome(left+1,right,s) || isPalindrome(left,right-1,s);
            }
            left++; right--;
        }
        return true;
    }
};