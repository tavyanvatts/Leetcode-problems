class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(2, vector<int>(3, -1)));
        for (int i = 0; i < 2; i++) {
            for (int j = 2; j >= 0; j--) {
                dp[1][i][j] = 0;
            }
        }
        for (int i = 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                dp[i][j][2] = 0;
            }
        }
        for (int ind = prices.size() - 1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int bought = 1; bought >= 0; bought--) {
                    if (buy) {
                        dp[0][buy][bought] =
                            max(-1 * prices[ind] + dp[1][0][bought],
                                dp[1][1][bought]);
                    } else {
                        dp[0][buy][bought] =
                            max(prices[ind] + dp[1][1][bought + 1],
                                dp[1][0][bought]);
                    }
                    dp[1][buy][bought] = dp[0][buy][bought];
                }
            }
        }
        return dp[0][1][0];
    }
};
