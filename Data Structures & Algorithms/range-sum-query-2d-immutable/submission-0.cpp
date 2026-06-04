class NumMatrix {
private:
    vector<vector<int>> a;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (a.empty()) return -1;
        int temp = 0;
        for (int i = row1; i <= row2; i++){
            for (int j = col1; j <= col2; j++){
               temp += a[i][j];
            }
        }
        return temp;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */