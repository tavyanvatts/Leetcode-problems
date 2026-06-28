class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < k; i++){
            sum = max(sum + nums[i], sum + (long long)nums[i]*mul);
            mul--;
        }
        return sum;
    }
};
