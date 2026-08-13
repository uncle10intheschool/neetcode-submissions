class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int idx1 = 0, idx2 = n-1;
        while (idx1 < idx2){
            int sum = numbers[idx1] + numbers[idx2];
            if (sum == target) return {idx1+1,idx2+1};
            else if (sum < target){
                idx1++;
            } else idx2--;
        }
        return {};
    }
};
