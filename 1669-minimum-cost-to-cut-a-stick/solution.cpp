class Solution {
public:
    int function(int n, vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int cut = i; cut <= j; cut++){
            int cost = cuts[j + 1] - cuts[i - 1] + function(n, cuts, i, cut - 1,dp) + function(n, cuts, cut + 1, j,dp);

            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) { 
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return function(n, cuts, 1, cuts.size() - 2, dp);
    }
};
