class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size()) return false;

        int count[256] = {0};
        for (int i = 0; i < s.size(); i++){
            count[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++){
            count[t[i]]--;
        }

        for (int i = 0; i < s.size(); i++){
            if (count[s[i]] != 0) return false;
        }
        return true;
    }
};
