class Solution {
private:
    int calcTrueFalseK(vector<int>& piles, int mid){
        long long res = 0;
        for (int i = 0; i < piles.size(); i++){
            res += (piles[i] + mid - 1) /mid;
        }
        return res;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = piles[0];
        for (int i = 1; i < piles.size(); i++) maxVal = max(piles[i],maxVal);

        int left = 1, right = maxVal;
        while (left < right){
            int mid = left + (right - left)/2;
            int hour = calcTrueFalseK(piles,mid);
            if (hour <= h) right = mid;
            else left = mid + 1; 
        }
        return left;
    }
};