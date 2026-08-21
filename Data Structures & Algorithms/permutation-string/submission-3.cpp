class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> myMapS1(26,0); // space: O(26) --> O(1)
        for (auto& c : s1) myMapS1[c - 'a']++;
        // time: O(s1)
        
        vector<int> myMapS2(26,0); // space: O(26) --> O(1)
        int l = 0;
        for (int r = 0; r < s2.size(); r++){ // time: O(s2)
            if (r-l+1 > s1.size()){
                myMapS2[s2[l] - 'a']--;
                l++;
            }
            myMapS2[s2[r] - 'a']++;
            if (myMapS1 == myMapS2) return true; // time O(26) --> O(1)
        }
        return false;
    }
};