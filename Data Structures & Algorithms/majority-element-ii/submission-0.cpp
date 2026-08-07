class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() <= 2) return nums;
        int m1,m2; int c1 = 0,c2 = 0;
        for (int num : nums){
            if (num == m1) c1++;
            else if (num == m2) c2++;
            else if (c1 == 0) {m1 = num; c1 = 1;}
            else if (c2 == 0) {m2 = num; c2 = 1;}
            else {c1--; c2--;}
        }
        c1 = 0, c2 = 0;
        for (int num : nums){
            if (m1 == num) c1++;
            else if (m2 == num) c2++;
        }
        vector<int> res;
        if (c1 > nums.size()/3) res.push_back(m1);
        if (c2 > nums.size()/3) res.push_back(m2);
        return res;
    }
};