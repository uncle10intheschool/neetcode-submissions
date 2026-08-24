class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int minLen = INT_MAX; int start = 0;

        unordered_map<char,int> m;
        for (char&c : t) m[c]++;
        int count = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            char c = s[r];
            if (m[c] > 0){ // đang cần --> count
                count++;
            }
            m[c]--;
            while (count == t.size()){
                if (r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }
                char del = s[l];
                m[del]++;
                if (m[del] > 0) count--;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};