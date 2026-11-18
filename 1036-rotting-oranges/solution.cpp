class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& grid2,
             queue<vector<int>>& q, int &t) {
        while (!q.empty()) {
            int n1 = q.front()[0];
            int n2 = q.front()[1];
            int t2 = q.front()[2] + 1;
            if (n1 - 1 >= 0) {
                if (grid[n1 - 1][n2] == 1 && grid2[n1 - 1][n2] != 1) {
                    grid2[n1 - 1][n2] = 1;
                    q.push({n1 - 1, n2, t2});
                    t = max(t, t2);
                }
            }
            if (n1 + 1 < grid.size()) {
                if (grid[n1 + 1][n2] == 1 && grid2[n1 + 1][n2] != 1) {
                    grid2[n1 + 1][n2] = 1;
                    q.push({n1 + 1, n2, t2});
                    t = max(t, t2);
                }
            }
            if (n2 - 1 >= 0) {
                if (grid[n1][n2 - 1] == 1 && grid2[n1][n2 - 1] != 1) {
                    grid2[n1][n2 - 1] = 1;
                    q.push({n1, n2 - 1, t2});
                    t = max(t, t2);
                }
            }
            if (n2 + 1 < grid[0].size()) {
                if (grid[n1][n2 + 1] == 1 && grid2[n1][n2 + 1] != 1) {
                    grid2[n1][n2 + 1] = 1;
                    q.push({n1, n2 + 1, t2});
                    t = max(t, t2);
                }
            }
            q.pop();
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int t = 0;
        vector<vector<int>> grid2(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({i, j, t});
            }
        }
        bfs(grid, grid2, q, t);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && grid2[i][j] == 0)
                    return -1;
            }
        }
        return t;
    }
};
