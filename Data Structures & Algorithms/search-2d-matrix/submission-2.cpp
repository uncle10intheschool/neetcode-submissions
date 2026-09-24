class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix.size();
        int rowSize = matrix[0].size();
        int left = 0, right = colSize*rowSize-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            int X = mid/rowSize;
            int Y = mid%rowSize;
            if (matrix[X][Y] == target) return true;
            else if (matrix[X][Y] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};