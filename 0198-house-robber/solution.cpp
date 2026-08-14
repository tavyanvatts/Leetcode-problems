class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n - 1];
        int prev2 = 0;
        int curri;
        for(int i = n - 2; i >= 0; i--){
            int sum1 = nums[i];
            if(i + 2 <= n - 1){
                sum1 += prev2;
            }
            int sum2 = 0 + prev;
            curri = max(sum1, sum2);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
