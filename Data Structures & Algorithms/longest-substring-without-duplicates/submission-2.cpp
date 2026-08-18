class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char> mySet;
        int maxLen = 0;
        auto left = s.begin();
        auto right = left;
        while (right != s.end()){
            if (mySet.find(*right) == mySet.end()){
                mySet.insert(*right);
                right++;
            } else {
                while (mySet.find(*right) != mySet.end()){
                    mySet.erase(*left);
                    left++;
                }
            }
            int currLen = mySet.size();
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};