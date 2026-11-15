class Solution {
public:
int function(vector<int>& nums, int ind, int last_ind, int lsign,vector<vector<vector<int>>> &dp){
    if(ind == nums.size()) return 0;
    if(dp[ind][last_ind][lsign + 1] != -1) return dp[ind][last_ind][lsign + 1];
    int take = 0, nottake = 0;
    if(lsign == 0 || (nums[ind] - nums[last_ind] < 0 && lsign > 0)){
        take = 1 + function(nums, ind + 1, ind, -1, dp);
    }
    if((lsign == 0 || nums[ind] - nums[last_ind] > 0 && lsign < 0)){
        take = max(take, 1 + function(nums, ind + 1, ind, 1, dp));
    }
    nottake = 0 + function(nums, ind + 1, last_ind, lsign, dp);

    return dp[ind][last_ind][lsign + 1] = max(take, nottake);
}
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int last_ind = 0;
        int lsign = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, -1)));
        return function(nums, 0, last_ind, lsign, dp);
    }
};
