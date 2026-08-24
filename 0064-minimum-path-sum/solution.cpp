class Solution {
public:
    int function(vector<vector<int>>& grid, int row, int col,
                 vector<vector<int>>& dp) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return grid[row][col];
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int res = INT_MAX;
        if (row + 1 < grid.size()) {
            int sum1 = grid[row][col] + function(grid, row + 1, col, dp);
            res = min(res, sum1);
        }
        if (col + 1 < grid[0].size()) {
            int sum2 = grid[row][col] + function(grid, row, col + 1, dp);
            res = min(res, sum2);
        }
        return dp[row][col] = res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        dp[row - 1][col - 1] = grid[row - 1][col - 1];
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int mini = INT_MAX;
                if (i == row - 1 && j == col - 1) continue; 
                    if(i + 1 < grid.size()){
                        int sum1 = grid[i][j] + dp[i+ 1][j];
                        mini = min(mini, sum1);
                    }
                    if(j + 1 < grid[0].size()){
                        int sum2 = grid[i][j] + dp[i][j + 1];
                        mini = min(mini, sum2);
                    }
            dp[i][j] = mini;
                
            }
        }
        return dp[0][0];
    }
};
