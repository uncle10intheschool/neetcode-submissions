class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;        
        for (int& x : nums) count[x]++;
        vector<int> res;
        for (auto& [num,freq] : count){
            if (freq > n/3) res.push_back(num);
        }
        return res;
    }
};