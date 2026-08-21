class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        unordered_map<char,int> myMapS1;
        for (auto& c : s1) myMapS1[c]++;

        for (int i = 0; i <= s2.size()-s1.size(); i++){
            string temp = s2.substr(i,s1.size());
            unordered_map<char,int> myMapS2;
            for (auto& c : temp) myMapS2[c]++;
            if (myMapS1 == myMapS2) return true;
        }
        return false;
    }
};