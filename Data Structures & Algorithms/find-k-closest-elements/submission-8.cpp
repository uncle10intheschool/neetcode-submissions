class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-k;
        while (l < r){
            int mid = l + (r-l)/2;
            if (abs(arr[mid] - x) <= abs(arr[mid+k] - x)){
                r = mid;
            } else l = mid + 1;
        }
        
        return vector<int> (arr.begin()+l, arr.begin()+l+k);
    }
};