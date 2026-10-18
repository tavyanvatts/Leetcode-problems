class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        visited[0][0] = 1;
        int i = 0, j = 0;
        vector<int> ans(2);
        while(i >= 0 && i < row && j >= 0 && j < col){
            ans[0] = i;
            ans[1] = j;
            if(grid[i][j] == 'R') j++;
            else if(grid[i][j] == 'U')i--;
            else if(grid[i][j] == 'D')i++;
            else if(grid[i][j] == 'L')j--;;
            if((i < 0) || (i >= row) || (j < 0) || (j >= col)) return ans;
            if(visited[i][j] == 1){
                return ans;
            }

            visited[i][j] = 1;
        }
        return ans;
    }
};
