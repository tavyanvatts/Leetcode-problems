class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long op = 0;
        long long cost = 0;
        long long resou = k;
        long long pv = k;
        for(int i = 0; i < n; i++){
            if(nums[i] > resou){
                long long nee = (nums[i] - resou + pv - 1)/pv;
                resou += nee*pv;
                op += nee;
            }
            resou -= nums[i];
        }
        long long mod = 1e9 + 7;
        long long a = op%mod;
        long long b = (op + 1)%mod;
        long long inv2 = 500000004;
        cost = (((a*b)%mod)*inv2)%mod;
        return cost%mod;
    }
};
