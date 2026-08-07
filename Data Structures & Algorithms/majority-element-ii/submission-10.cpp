class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int &x : nums){
            count[x]++;

            if (count.size() > 2){
                unordered_map<int,int> newCount;
                for (auto& [num,freq] : count){
                    if (freq > 1) newCount[num] = freq-1;
                }
                count = newCount;
            }
        }
        vector<int> res;
        for (auto& [num,freq] : count){ // only 2 num
            int dup = 0;
            for (int& x : nums){
                if (x == num) dup++;
            }
            if (dup > nums.size()/3) res.push_back(num);
        }
        return res;
    }
};
