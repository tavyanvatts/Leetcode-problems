class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> ans = {-1,-1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(nums[i] + nums[j] == target && nums[i] > nums[j]){
                    if(nums[i]*nums[j] > maxi){
                        maxi = nums[i]*nums[j];
                        ans = {i, j};
                    }
                }
            }
        }
        return ans;
    }
};
