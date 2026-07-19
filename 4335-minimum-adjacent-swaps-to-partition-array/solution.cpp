class Solution {
public:
const int mod = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < a) nums[i] = 0;
            else if(nums[i] > b) nums[i] = 2;
            else nums[i] = 1;
        }
        long long cnt0 = 0;
        long long cnt1 = 0;
        long long cnt2 = 0;
        long long cnts = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt1++;
                cnts += cnt2;
            }
            else if(nums[i] == 0){
                cnt0++;
                cnts += cnt2;
                cnts += cnt1;
            }
            else cnt2++;
        }
        return cnts%mod;
    }
};
