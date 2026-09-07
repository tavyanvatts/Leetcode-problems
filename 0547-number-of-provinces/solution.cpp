class Solution {
public:
void dfs(vector<vector<int>>& isConnected, int start, vector<int>& arr){
    arr[start] = 1;
    for(int i = 0; i < isConnected.size(); i++){
        if(isConnected[start][i] == 1 && arr[i] == 0){
            dfs(isConnected, i, arr);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> arr(n ,0);
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                cnt++;
                dfs(isConnected, i, arr);
            }
        }
        return cnt;
    }
};
