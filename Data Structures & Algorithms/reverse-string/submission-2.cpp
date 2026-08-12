class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        vector<char>::iterator left = s.begin();      
        vector<char>::iterator right = s.end()-1;
        while (left < right){
            char temp = *left;
            *left = *right;
            *right = temp;

            left++; right--;
        }
    }
};