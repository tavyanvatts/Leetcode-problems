class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        while (!q.empty()) {
            int n1 = q.front().first;
            int n2 = q.front().second;
            vis[n1][n2] = 1;
            if (n1 - 1 >= 0) {
                if (grid[n1 - 1][n2] == 1 && vis[n1 - 1][n2] != 1) {
                    vis[n1 - 1][n2] = 1;
                    q.push({n1 - 1, n2});
                }
            }
            if (n1 + 1 < grid.size()) {
                if (grid[n1 + 1][n2] == 1 && vis[n1 + 1][n2] != 1) {
                    vis[n1 + 1][n2] = 1;
                    q.push({n1 + 1, n2});
                }
            }
            if (n2 - 1 >= 0) {
                if (grid[n1][n2 - 1] == 1 && vis[n1][n2 - 1] != 1) {
                    vis[n1][n2 - 1] = 1;
                    q.push({n1, n2 - 1});
                }
            }
            if (n2 + 1 < grid[0].size()) {
                if (grid[n1][n2 + 1] == 1 && vis[n1][n2 + 1] != 1) {
                    vis[n1][n2 + 1] = 1;
                    q.push({n1, n2 + 1});
                }
            }
            q.pop();
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] == 1)
                q.push({0, i});
            if (grid[grid.size() - 1][i] == 1)
                q.push({grid.size() - 1, i});
        }
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 1)
                q.push({i, 0});
            if (grid[i][grid[0].size() - 1] == 1)
                q.push({i, grid[0].size() - 1});
        }
        bfs(q, grid, vis);
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
