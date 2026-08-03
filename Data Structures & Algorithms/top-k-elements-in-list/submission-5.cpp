class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k > nums.size()) return {};
        int n = nums.size();
        unordered_map<int,int> myMap;
        for (const int& x : nums) myMap[x]++;

        vector<vector<int>> fakeTable(n+1);
        for (const auto& [key,count] : myMap){
            fakeTable[count].emplace_back(key);
        }

        vector<int> res;
        for (int i = fakeTable.size()-1; i > 0; i--){
            for (const int& x : fakeTable[i]){
                res.emplace_back(x);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};

