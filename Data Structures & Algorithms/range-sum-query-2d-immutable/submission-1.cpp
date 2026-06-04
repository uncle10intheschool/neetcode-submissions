class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); // vuông nên lấy [0] vẫn đc
        prefix = vector<vector<int>> (m,vector<int>(n,0));

        for (int i = 0; i < m; i++){
            prefix[i][0] = matrix[i][0];
            for (int j = 1; j < n; j++){
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; i++){
            if (col1 > 0) {
                res += prefix[i][col2] - prefix[i][col1 - 1];
            } else {
                res += prefix[i][col2];
            }
        }
       return res; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */