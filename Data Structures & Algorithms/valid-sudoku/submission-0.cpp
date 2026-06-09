class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;

        // rows
        for (int i = 0; i < 9; i++){
            unordered_set<int> row(9);
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (row.count(board[i][j])) return false;
                row.insert(board[i][j]);
            }
        }

        // cols
        for (int i = 0; i < 9; i++){
            unordered_set<int> col(9);
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                if (col.count(board[j][i])) return false;
                col.insert(board[j][i]);
            }
        }

        // 3x3
        for (int sq = 0; sq < 9; sq++){
            unordered_set<int> square(9);
            for (int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++){
                    int r = (sq/3) * 3 + x;
                    int c = (sq%3) * 3 + y;
                    if (board[r][c] == '.') continue;
                    if (square.count(board[r][c])) return false;
                    square.insert(board[r][c]);
                }
            }
        }

        return true;
    }
};
