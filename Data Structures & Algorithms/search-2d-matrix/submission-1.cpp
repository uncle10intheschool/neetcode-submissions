class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix.size();
        int rowSize = matrix[0].size();
        vector<int> a(colSize*rowSize);
        for (int i = 0; i < a.size(); i++){
            a[i] = matrix[i/rowSize][i%rowSize];
        }
        int left = 0, right = a.size()-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (a[mid] == target) return true;
            else if (a[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
