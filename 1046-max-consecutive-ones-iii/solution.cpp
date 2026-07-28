class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0 = 0;
        int start = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cnt0++;
            if (cnt0 > k) {
                if(cnt0 > k){
                    if(nums[start] == 0)cnt0--;
                    start++;
                }
            }
            maxi = max(maxi, i - start + 1);
        }
        return maxi;
    }
};
