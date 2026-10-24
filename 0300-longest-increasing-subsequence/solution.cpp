class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int len = 0;
        for(int i = 0; i < n; i++){
            if(ans.empty() || nums[i] > ans.back()){
                ans.push_back(nums[i]);
                len++;
            }
            else if(nums[i] < ans.back()){
                ans[lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin()] = nums[i];
            }
        }
        return len;
    }
};
