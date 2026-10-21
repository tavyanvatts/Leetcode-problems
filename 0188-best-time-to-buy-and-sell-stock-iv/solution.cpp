class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int buy = 1;
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                dp[1][0][j] = 0;
            }
        }
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= 1; j++) {
                dp[1][i][j] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int j = 1; j <= k; j++) {
                for (int buy = 0; buy <= 1; buy++) {
                    if (buy) {
                        dp[0][j][buy] =
                            max(-1 * prices[ind] + dp[1][j][0],
                                dp[1][j][1]);
                    } else {
                        dp[0][j][buy] = max(prices[ind] + dp[1][j - 1][1],
                                     dp[1][j][0]);
                    }
                    dp[1][j][buy] = dp[0][j][buy];
                }
            }
        }
        return dp[0][k][1];
    }
};
