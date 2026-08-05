class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int l = 0;
        int r = 0;
        int maxi = INT_MIN;
        while(r < n){
            if(nums[r] == 0) cnt0++;
            while(cnt0 > 1){
                if(nums[l] == 0) cnt0--;
                l++;
            }
            maxi = max(maxi, r - l);
            r++;
        }
        return maxi;
    }
};
