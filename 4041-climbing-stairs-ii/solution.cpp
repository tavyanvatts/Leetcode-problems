class Solution {
public:
int function(int n, vector<int>& costs, int stair, vector<int>& dp){
    if(stair == n) return 0;
    if(dp[stair] != -1) return dp[stair];
    int cost = 0;
    int mini = INT_MAX;
    for(int i = 1; i < 4; i++){
        if(stair + i <= n)cost = costs[stair + i - 1] + i*i + function(n, costs, stair + i, dp);
        mini = min(mini, cost);
    }
    return dp[stair] = mini;
}
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return function(n, costs, 0, dp);
    }
};
