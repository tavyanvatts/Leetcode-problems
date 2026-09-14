class Solution {
public:

int function(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
if(ind == 0){
        if(amount%coins[ind] == 0) return amount/coins[ind];
    
    return 1e9;
}
if(dp[ind][amount] != -1) return dp[ind][amount];

int take = 1e9, nottake = 0, take2 = 1e9;
    if(coins[ind] <= amount){
        take = 1 + function(coins, amount - coins[ind], ind, dp);
        take2 = 1 + function(coins, amount - coins[ind], ind - 1, dp);
    }
    nottake = 0 + function(coins, amount, ind - 1, dp);

    return dp[ind][amount] = min(min(take2,take), nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int ind = coins.size() - 1;
        vector<vector<int>> dp(ind + 1, vector<int>(amount + 1, -1));
        int ans = function(coins, amount, ind, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};
