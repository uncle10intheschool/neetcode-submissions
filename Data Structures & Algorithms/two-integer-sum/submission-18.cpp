class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++){
            a.emplace_back(nums[i],i);
        }
        sort(a.begin(),a.end());
        int i = 0,j = n-1;
        while (i < j){
            int sum = a[i].first + a[j].first;
            if (sum == target){
                return {min(a[i].second,a[j].second),max(a[i].second,a[j].second)};
            } else if (sum < target) i++;
            else j--;
        }
        return {};
    }
};
