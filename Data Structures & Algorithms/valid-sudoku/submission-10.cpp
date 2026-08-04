class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // row & col
        map<int,unordered_set<char>> row;
        map<int,unordered_set<char>> col;
        // 3x3
        map<pair<int,int>,unordered_set<char>> square;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                
                pair<int,int> point = {i/3,j/3};
                if (row[i].find(board[i][j]) != row[i].end()    || 
                col[j].find(board[i][j]) != col[j].end()        || 
                square[point].find(board[i][j]) != square[point].end()) return false;
                
                row[i].emplace(board[i][j]);
                col[j].emplace(board[i][j]);
                square[point].emplace(board[i][j]);
            }
        }        
        return true;
    }
};