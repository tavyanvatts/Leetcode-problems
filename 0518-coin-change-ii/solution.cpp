class Solution {
public:

int function(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp){
if(ind == 0){
    if(amount%coins[ind] == 0) return 1;
    return 0;
}
if(dp[ind][amount] != -1) return dp[ind][amount];

    int take = 0, nottake = 0;
    if(coins[ind] <= amount){take = function(amount - coins[ind], coins, ind, dp);}
    nottake = function(amount, coins, ind - 1, dp);

    return dp[ind][amount] = take + nottake;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1 , -1));
        return function(amount, coins, coins.size() - 1, dp);
    }
};
