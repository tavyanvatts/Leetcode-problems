class Solution {
public:
void wsearcher(bool &ok, vector<vector<char>>& board, string &word, int i, int j, int currchar){
    if(currchar == word.length()){
        ok = true;
        return;
    }
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[currchar]){
        return;
    }
    if(board[i][j] == word[currchar]){
        board[i][j] = '.';
        wsearcher(ok, board, word, i + 1, j, currchar + 1);
        if(ok) return;
        wsearcher(ok, board, word, i - 1, j, currchar + 1);
        if(ok) return;
        wsearcher(ok, board, word, i, j + 1, currchar + 1);
        if(ok) return;
        wsearcher(ok, board, word, i, j - 1, currchar + 1);
        if(ok) return;
        board[i][j] = word[currchar];
    }
}
    bool exist(vector<vector<char>>& board, string word) {
        bool ok = false;
        int currchar = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[currchar]){
                    wsearcher(ok, board, word, i, j, currchar);
                    if(ok) break;
                }
            }
            if(ok) break;
        }
        return ok;
    }
};
