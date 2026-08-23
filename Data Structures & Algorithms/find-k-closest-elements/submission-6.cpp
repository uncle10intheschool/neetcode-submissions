class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        while (l < r){
            int mid = l + (r-l)/2;
            if (arr[mid] < x){
                l = mid + 1;
            } else { // arr[mid] >= x
                r = mid; // have == x so we r = mid not mid - 1;
            }
        }

        l = l-1; r =  l+1;
        while (r-l-1 < k){
            if (l < 0) r++;
            else if (r >= arr.size()) l--;
            else if (abs(arr[l]-x) <= abs(arr[r] - x)) l--;
            else r++;
        }
        
        return vector<int> (arr.begin() +l+1, arr.begin()+r);
    }
};