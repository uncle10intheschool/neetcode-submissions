class Solution {
private:
    bool alphaNum(char c){
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' ||
        c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        string::iterator left = s.begin();
        string::iterator right = s.end()-1;

        while (left < right){
            while (!alphaNum(*left) && left < right) left++;
            while (!alphaNum(*right) && right > left) right--;

            if (tolower(*left) != tolower(*right)) return false;

            left++; right--;
        }
        return true;
    }
};