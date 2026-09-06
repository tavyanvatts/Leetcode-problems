class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0; i < n/2; i++){
            sum1 += nums[i];
        }
        for(int i = n/2; i < n; i++){
            sum2 += nums[i];
        }
        if(sum1 > sum2) cnt++;
        for(int i = 1; i < n; i++){
            int l = nums[i - 1];
            int c = nums[(i - 1 + n/2)%n];
            sum1 -= l;
            sum1 += c;
            sum2 -= c;
            sum2 += l;
            if(sum1 > sum2)cnt++;
        }
        return cnt;
    }
};
