class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string,vector<string>> map;
        for (string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            map[key].emplace_back(s);
        }

        vector<vector<string>> res;
        for (auto [key,data]: map){
            res.emplace_back(data);
        }
        return res;
    }
};
