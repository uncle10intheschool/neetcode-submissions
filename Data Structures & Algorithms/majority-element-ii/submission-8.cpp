class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return {};
        unordered_map<int,int> count;        
        for (int& x : nums) count[x]++;
        vector<int> res;
        for (auto& [num,freq] : count){
            if (freq > n/3) res.push_back(num);
        }
        return res;
    }
};