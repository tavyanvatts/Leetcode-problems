class Solution {
public:
    long long mp(long long x, long long y, long long MOD){
        long long res = 1;
        while(y > 0){
            if(y&1) res = (res*x)%MOD;
            x = (x*x)%MOD;
            y >>= 1;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int MOD = 1e9 + 7;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int w = nums[i]%10;
            long long d = floor(nums[i]/10);
            int dig = (int)log10(d) + 1;
            long long  c = (long long)pow(10, dig - w);
            long long x = d/c;
            long long y = d%c;
            sum = (sum + mp(x,y,MOD))%MOD;
        }
        return sum;
    }
};
