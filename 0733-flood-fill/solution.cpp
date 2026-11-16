class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& image, int sr,
             int sc) {
        vis[sr][sc] = 1;
        if (sr - 1 >= 0) {
            if (image[sr - 1][sc] == image[sr][sc] && vis[sr - 1][sc] == 0) {
                dfs(vis, image, sr - 1, sc);
            }
        }
        if (sr + 1 < image.size()) {
            if (image[sr + 1][sc] == image[sr][sc] && vis[sr + 1][sc] == 0) {
                dfs(vis, image, sr + 1, sc);
            }
        }
        if (sc - 1 >= 0) {
            if (image[sr][sc - 1] == image[sr][sc] && vis[sr][sc - 1] == 0) {
                dfs(vis, image, sr, sc - 1);
            }
        }
        if (sc + 1 < image[0].size()) {
            if (image[sr][sc + 1] == image[sr][sc] && vis[sr][sc + 1] == 0) {
                dfs(vis, image, sr, sc + 1);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), 0));
        dfs(vis, image, sr, sc);
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                if (vis[i][j] == 1)
                    image[i][j] = color;
            }
        }
        return image;
    }
};
