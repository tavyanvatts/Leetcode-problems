class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> hash;
            int sum = 0;
            for (int j = i; j < n; j++) {
                hash[(2 * nums[j] % k + k)%k]++;
                sum += nums[j];
                if ((sum % k + k)%k == 0 || hash.find((sum % k + k)%k) != hash.end())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
