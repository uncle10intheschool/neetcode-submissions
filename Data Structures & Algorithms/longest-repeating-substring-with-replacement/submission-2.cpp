class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> myMap;
        int maxLen = 0;
        int l = 0; int max_freq = 0;
        for (int r = 0; r < s.size(); r++){
            myMap[s[r]]++;
            max_freq = max(max_freq,myMap[s[r]]);
            while ((r-l+1) - max_freq > k){
                myMap[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};