class Solution {
public:
    int robber(vector<int>& nums, vector<int>& dp, int ind) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        int sum1 = 0 + robber(nums, dp, ind + 1);
        
        int sum2 = nums[ind] + robber(nums, dp, ind + 2);

        return dp[ind] = max(sum1, sum2);
    }
    int rob(vector<int>& nums) {
        vector<int> nums2(nums.begin(), nums.end() - 1);
            vector<int> dp(nums.size(), -1);
            vector<int> dp2(nums2.size(), -1);
            int ans1 = robber(nums, dp, 1);
            int ans2 = robber(nums2, dp2, 0);
            return (nums.size() == 1) ? nums[0] : max(ans1, ans2);
        }
};
