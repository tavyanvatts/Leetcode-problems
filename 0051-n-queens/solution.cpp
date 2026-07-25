class Solution {
public:
void queengen(vector<vector<string>> &ans,vector<string> &board,int col,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    bool ok;
    for(int i = 0; i < n; i++){
        ok = true;
        int row = i;
        int column = col;
        // code that ensures that placing a queen is safe
        while(column >= 0){
            if(board[row][column] == 'Q') ok = false;
            column--;
        }
        column = col;
        while(row >= 0 && column >= 0){
            if(board[row][column] == 'Q') ok = false;
            column--;
            row--;
        }
        column = col;
        row = i;
        while(row < n && column >= 0){
            if(board[row][column] == 'Q') ok = false;
            column--;
            row++;
        }
        //safety code ends
        if(ok){board[i][col] = 'Q';
        queengen(ans, board, col + 1, n);
        board[i][col] = '.';}
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        int col = 0;
        queengen(ans, board, col, n);
        return ans;
    }
};
