class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        
        unordered_map<int,unordered_set<char>> row(9);
        unordered_map<int,unordered_set<char>> col(9);
        map<pair<int,int>,unordered_set<char>> square;
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                pair<int,int> point = {i/3,j/3};
                if (board[i][j] == '.') continue;
                if (row[i].count(board[i][j]) || col[j].count(board[i][j]) || square[point].count(board[i][j])) return false;

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[point].insert(board[i][j]);
            }
        }

        return true;
    }
};
