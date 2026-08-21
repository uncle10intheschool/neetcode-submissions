class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        unordered_map<char,int> myMapS1;
        for (auto& c : s1) myMapS1[c]++;
        
        unordered_map<char,int> myMapS2;
        int l = 0;
        for (int r = 0; r < s2.size(); r++){
            if (r-l+1 > s1.size()){
                myMapS2[s2[l]]--;
                if (myMapS2[s2[l]] == 0) myMapS2.erase(s2[l]);
                l++;
            }
            myMapS2[s2[r]]++;
            if (myMapS1 == myMapS2) return true;
        }
        return false;
    }
};
