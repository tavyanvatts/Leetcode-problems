class Solution {
public:
bool function(vector<int>& nums, int ind, unordered_map<int, bool> &dp){
    if(ind >= nums.size() - 1) return true;
    if(dp.find(ind) != dp.end()) return dp[ind];

    for(int i = 1; i <= nums[ind]; i++){
        if(function(nums, ind + i, dp)) return true;
    }
    return dp[ind] = false;
}
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> dp;
        return function(nums, 0, dp);
    }
};
