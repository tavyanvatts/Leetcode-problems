class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }
        for (int ind = 1; ind < coins.size(); ind++) {
            for (int a = 0; a < amount + 1; a++) {
                int take = 1e9, nottake = 0, take2 = 1e9;
                if (coins[ind] <= a) {
                    take = 1 + dp[ind][a - coins[ind]];
                    take2 = 1 + dp[ind - 1][a - coins[ind]];
                }
                nottake = 0 + dp[ind - 1][a];

                dp[ind][a] = min(min(take, take2), nottake);
            }
        }
        int ans = dp[coins.size() - 1][amount];
        return (ans == 1e9) ? -1 : ans;
    }
};
