class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxcnt = INT_MIN;
        int n = nums.size();
        while(r < n){
            if(nums[r] == 1){
                maxcnt = max(maxcnt, r - l + 1);
            }
            if(nums[r] == 0) l = r + 1;
            r++;
        }
        return (maxcnt == INT_MIN) ? 0 : maxcnt;
    }
};
