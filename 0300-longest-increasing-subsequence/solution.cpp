class Solution {
public:

int function(vector<int>& nums, int ind, int prev, vector<vector<int>> &dp){
    if(ind == nums.size()) return 0;
    if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
    int length = 0;
    if(prev == -1 || nums[prev] < nums[ind]){
        int l1 = 1 + function(nums, ind + 1, ind, dp);
        length = max(length, l1);
    }
    length = max(length, function(nums, ind + 1, prev, dp));
    return dp[ind][prev + 1] = length;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 2, -1));
        return function(nums, 0, -1, dp);
    }
};
