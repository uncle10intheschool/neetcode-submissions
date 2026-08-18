class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char> mySet;
        int maxLen = 0;
        auto left = s.begin();
        auto right = left;
        while (right != s.end()){
            while (mySet.find(*right) != mySet.end()){
                mySet.erase(*left);
                left++;
            }
            mySet.insert(*right);
            right++;
            int currLen = mySet.size();
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};