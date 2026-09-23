class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 0; int right = x/2;
        int res = 0;
        while (left <= right){
            int mid = left + (right-left)/2;
            long long bp = (long long)mid*mid;
            if (bp == x) return mid;
            else if (bp > x) right = mid-1;
            else left = mid+1;
        }
        return right;
    }
};