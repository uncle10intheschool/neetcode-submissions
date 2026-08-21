class Solution {
private:
    bool checkDist(auto& left, auto& right,const int& x){
        int distL = abs(*left - x);
        int distR = abs(*right - x);
        if (distL < distR) return true;
        else if (distL > distR) return false;
        else {
            return *left < *right;
        }
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size()) return arr;
        int n = arr.size();
        auto left = arr.begin(), right = arr.end()-1;
        while (left <= right){
            if (right - left + 1 == k) break;

            bool isUp = checkDist(left,right,x);
            if (isUp){ // left < right --> right--
                right--;
            } else left++;
        }

        vector<int> res(left,right+1);
        return res;
    }
};