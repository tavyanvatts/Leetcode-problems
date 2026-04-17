class Solution {
public:
    long long maxFrequency(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        long long presum = 0;
        long long j = 0;
        long long winmax = INT_MIN;
        for(long long i = 0; i < nums.size(); i++){
            presum += nums[i];
            if((i - j + 1)*nums[i] - presum <= k){
                winmax = max(winmax, i - j + 1);
            }
            else{
                presum -= nums[j];
                j++;
            }
        }
        return winmax;
    }
};
