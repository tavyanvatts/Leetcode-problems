class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i,
             int j) {
        int R = grid.size();
        int C = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int n1 = q.front().first;
            int n2 = q.front().second;
            vis[n1][n2] = 1;
            q.pop();
            if (n1 - 1 >= 0) {
                if (grid[n1 - 1][n2] == '1' && vis[n1 - 1][n2] == 0)
                    {
                        vis[n1 - 1][n2] = 1;
                        q.push({n1 - 1, n2});}
            }
            if (n1 + 1 < R) {
                if (grid[n1 + 1][n2] == '1' && vis[n1 + 1][n2] == 0)
                    { vis[n1 + 1][n2] = 1;
                    q.push({n1 + 1, n2});}
            }
            if (n2 - 1 >= 0) {
                if (grid[n1][n2 - 1] == '1' && vis[n1][n2 - 1] == 0)
                {vis[n1][n2 -1] = 1;
                    q.push({n1, n2 - 1});}
            }
            if (n2 + 1 < C) {
                if (grid[n1][n2 + 1] == '1' && vis[n1][n2 + 1] == 0){
                    vis[n1][n2 + 1] = 1;
                    q.push({n1, n2 + 1});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};
