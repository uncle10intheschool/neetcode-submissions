class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); // vuông nên lấy [0] vẫn đc
        prefix = vector<vector<int>> (m+1,vector<int>(n+1,0));

        for (int i = 0; i < m; i++){
            int presum = 0;
            for (int j = 0; j < n; j++){
                presum += matrix[i][j];
                int above = prefix[i][j+1];
                prefix[i+1][j+1] = presum + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = prefix[row2][col2];
        int above = prefix[row1-1][col2];
        int left = prefix[row2][col1-1];
        int topLeft = prefix[row1-1][col1-1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */