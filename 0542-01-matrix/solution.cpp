class Solution {
public:

void bfs(vector<vector<int>>& mat,  vector<vector<int>> &dist,  vector<vector<int>> &vis, queue<vector<int>> &q){
    while(!q.empty()){
        int n1 = q.front()[0], n2 = q.front()[1], d = q.front()[2];
        dist[n1][n2] = d;
        if(n1 - 1 >= 0 && vis[n1 - 1][n2] != 1){
            if(mat[n1 - 1][n2] == 1){q.push({n1 - 1, n2, d + 1});
            vis[n1 - 1][n2] = 1;}
        }
        if(n1 + 1 < mat.size() && vis[n1 + 1][n2] != 1){
            if(mat[n1 + 1][n2] == 1){q.push({n1 + 1, n2, d + 1});
             vis[n1 + 1][n2] = 1;}
        }
        if(n2 - 1 >= 0 && vis[n1][n2 - 1] != 1){
            if(mat[n1][n2 - 1] == 1){
                q.push({n1, n2 - 1, d + 1});
            
            vis[n1][n2 - 1] = 1;}
        }
                if(n2 + 1 < mat[0].size() && vis[n1][n2 + 1] != 1){
            if(mat[n1][n2 + 1] == 1){
                q.push({n1, n2 + 1, d + 1});
            
            vis[n1][n2 + 1] = 1;}
        }
        q.pop();
    }
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0) q.push({i, j, 0});
            }
        }
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), 0)), vis(mat.size(), vector<int>(mat[0].size(), 0));
        bfs(mat, dist, vis, q);
        return dist;
    }
};
