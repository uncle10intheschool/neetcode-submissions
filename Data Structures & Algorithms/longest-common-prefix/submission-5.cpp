class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int minLen = strs[0].size() < strs.back().size() ? strs[0].size() : strs.back().size();
        for (int i = 0; i < minLen; i++){
            if (strs[0][i] != strs.back()[i]){
                return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};