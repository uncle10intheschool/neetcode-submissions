class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator left = s.begin();
        string::iterator right = s.end()-1;

        while (left < right){
            while (!isalnum(*left) && left < right) left++;
            while (!isalnum(*right) && right > left) right--;

            if (tolower(*left) != tolower(*right)) return false;

            left++; right--;
        }
        return true;
    }
};