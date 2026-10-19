class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, -1));
        int ind = prices.size();
        for(auto &it : dp[1]){
            it = 0;
        }
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                if(j){dp[0][j] = max(-1*prices[i] + dp[1][0], 0 + dp[1][1]);}
                else dp[0][j] = max(prices[i] + dp[1][1], dp[1][0]);
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
    }
};
