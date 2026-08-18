class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char,int> myMap;
        int maxLen = 0;
        int left = 0, right = 0;
        while (right < s.size()){
            if (myMap.find(s[right]) != myMap.end()){
                left = max(myMap[s[right]] + 1, left);
            }
            myMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};