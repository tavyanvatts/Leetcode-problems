class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, -1));
        for(auto &it : dp[1]){
            it = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                if(j){
                    dp[0][j] = max(dp[1][0] - prices[i], dp[1][1]);
                }
                else{
                    dp[0][j] = max(prices[i] + dp[1][1] - fee, dp[1][0]);
                }
                dp[1] = dp[0];
            }
        }
        return dp[0][1];
    }
};
