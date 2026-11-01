class Solution {
public:

int function(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
if(i > j) return 0;
if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    for(int last = i; last <= j; last++){
        int points = nums[i - 1]*nums[last]*nums[j + 1] + function(nums, i, last - 1, dp) + function(nums, last + 1, j, dp);

        maxi = max(maxi, points);
    }
    return dp[i][j] = maxi;
}
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, - 1));
        return function(nums, 1, nums.size() - 2, dp);
    }
};
