class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        auto w1 = word1.begin();
        auto w2 = word2.begin();
        while (w1 != word1.end() && w2 != word2.end()){
            res += *w1++;
            res += *w2++;
        }
        while (w1 != word1.end()) res += *w1++;
        while (w2 != word2.end()) res += *w2++;
        return res;
    }
};