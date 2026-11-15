class Solution {
public:
    long long function(vector<int>& nums, int ind, vector<long long> &dp) {
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long score = nums[ind], ans = LLONG_MIN;
        if(score%3 == 0){
            ans = max(ans, score - function(nums, ind + 1, dp));
        }
        else ans = max(ans, score + function(nums, ind + 1, dp));

        if(ind + 1 < nums.size()){
            score = nums[ind] + nums[ind + 1];
            if(score%3 == 0){
                ans = max(ans, score - function(nums, ind + 2, dp));
            }
            else ans = max(ans, score + function(nums, ind + 2, dp));
        }
        return dp[ind] = ans;
    }
    long long maxDifference(vector<int>& nums) {
        vector<long long> dp(nums.size() + 1, -1);
        return function(nums, 0, dp);
    }
};
