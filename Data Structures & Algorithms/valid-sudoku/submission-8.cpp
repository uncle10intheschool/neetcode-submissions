class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // row & col
        unordered_set<char> row(n);
        unordered_set<char> col(n);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (row.find(board[i][j]) != row.end()) return false;
                row.emplace(board[i][j]);
            }
            row.clear();

            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                if (col.find(board[j][i]) != col.end()) return false;
                col.emplace(board[j][i]);
            }
            col.clear();
        }        
        // 3x3
        map<pair<int,int>,unordered_set<char>> square;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                pair<int,int> point = {i/3,j/3};
                if (board[i][j] == '.') continue;
                if (square[point].find(board[i][j]) != square[point].end()) return false;
                square[point].emplace(board[i][j]);
            }
        }

        return true;
    }
};

