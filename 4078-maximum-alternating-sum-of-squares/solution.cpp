class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            return abs(a) < abs(b);
        });
        int l = 0;
        int r = nums.size() - 1;
        long long ans = 0;
        while(l <= r){
            ans += nums[r]*nums[r];
            if(l == r) break;
            ans -= nums[l]*nums[l];
            l++;
            r--;
        }
        if(l == r){

        }
        return ans;
    }
};
