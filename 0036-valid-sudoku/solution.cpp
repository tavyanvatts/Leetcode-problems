class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            unordered_map<char, int> hash;
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '.')
                    continue;
                if (hash.find(board[i][j]) != hash.end()) {
                    return false;
                }
                hash[board[i][j]]++;
            }
        }
        for (int j = 0; j < cols; j++) {
            unordered_map<char, int> hash;
            for (int i = 0; i < rows; i++) {
                if (board[i][j] == '.')
                    continue;
                if (hash.find(board[i][j]) != hash.end()) {
                    return false;
                }
                hash[board[i][j]]++;
            }
        }
        for (int i = 0; i < 7; i += 3) {
            for (int j = 0; j < 7; j += 3) {
                unordered_map<char, int> hash;
                for (int k = i; k < i + 3; k++) {
                    for (int c = j; c < j + 3; c++) {
                        if (board[k][c] == '.')
                            continue;
                        if (hash.find(board[k][c]) != hash.end()) {
                            return false;
                        }
                        hash[board[k][c]]++;
                    }
                }
            }
        }
        return true;
    }
};
