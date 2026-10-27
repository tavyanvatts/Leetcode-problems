class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    if(dp[i] < 1 + dp[prev]) dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};
