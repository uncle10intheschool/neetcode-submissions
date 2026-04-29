class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()) return false;

        int count[256] = {0};
        for (int i = 0; i < s.size(); i++){
            count[(int)s[i]]++;
        }

        for (int i = 0; i < t.size(); i++){
            count[(int)t[i]]--;
        }

        for (int i = 0; i < s.size(); i++){
            if (count[(int)s[i]] != 0) return false;
        }
        return true;
    }
};