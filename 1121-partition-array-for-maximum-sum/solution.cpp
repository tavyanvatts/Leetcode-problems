class Solution {
public:
    int function(vector<int>& arr, int k, int start, vector<int> &dp) {

        if (start == arr.size())
            return 0;
        if(dp[start] != -1) return dp[start];

        int maxi = INT_MIN;
        int sum = 0;
        int ans = INT_MIN;
        for (int end = start; (end < start + k && end < arr.size()); end++) {
            if (arr[end] > maxi)
                maxi = arr[end];
            sum = (end - start + 1) * maxi + function(arr, k, end + 1, dp);

        ans = max(ans, sum);
        }
        return dp[start] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return function(arr, k, 0, dp);
    }
};
