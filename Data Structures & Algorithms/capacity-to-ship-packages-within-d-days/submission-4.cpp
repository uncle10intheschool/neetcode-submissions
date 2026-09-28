class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = weights[0], right = weights[0];
        for (int i = 1; i < weights.size(); i++){
            left = max(left,weights[i]);
            right += weights[i];
        }
        while (left < right){
            int mid = left + (right - left)/2;
            // ======================
            int res = 0; int count = 0;
            for (int i = 0; i < weights.size(); i++){
                if (res + weights[i] > mid){
                    res = 0;
                    count++;
                }
                res += weights[i];
            }
            if (res > 0) count++;
            // ======================
            if (count <= days){
                right = mid;
            } else left = mid + 1;
        }
        return right;
    }
};