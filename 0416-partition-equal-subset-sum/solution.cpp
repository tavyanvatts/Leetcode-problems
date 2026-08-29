class Solution {
public:

bool function(vector<int>& nums,vector<vector<int>>& dp, int ind, int target){
    if(target == 0) return true;
    if(ind == 0) return (target == nums[0]);
    if(dp[ind][target] != -1) return dp[ind][target];
    bool take = false;
    if(target >= nums[ind]){take = function(nums, dp, ind - 1, target - nums[ind]);}

    bool nott = function(nums,dp, ind - 1, target);

    return dp[ind][target] = (take || nott);
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if((sum&1) == 1) return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return function(nums, dp, n - 1, target);
    }
};
