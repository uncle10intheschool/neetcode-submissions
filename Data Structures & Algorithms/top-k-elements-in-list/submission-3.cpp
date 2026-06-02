class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // freq by a[i]
        unordered_map<int,int> myMap; // key: a[i] | data: count 
        for (const int& x: nums){
            myMap[x]++;
        }
        // freq by count
        vector<vector<int>> freq(nums.size()+1);
        for (auto [key,data] : myMap){
            freq[data].emplace_back(key);
        }
        
        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--){
            for (int x: freq[i]){
                res.push_back(x);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
