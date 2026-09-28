class Solution {
private:
    bool checkDays(int maxCap,vector<int>& w, int target){
        int res = 0; int count = 0;
        for (int i = 0; i < w.size(); i++){
            if (res + w[i] > maxCap){
                res = 0;
                count++;
            }
            res += w[i];
        }
        if (res > 0) count++;
        return count <= target;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = weights[0], right = weights[0];
        for (int i = 1; i < weights.size(); i++){
            left = max(left,weights[i]);
            right += weights[i];
        }
        while (left < right){
            int mid = left + (right - left)/2;
            if (checkDays(mid,weights,days)){
                right = mid;
            } else left = mid + 1;
        }
        return right;
    }
};