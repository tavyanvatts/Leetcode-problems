class Solution {
public:

int junction(int n, int d, vector<int> &arr, int sum1, int ind, vector<vector<int>>& dp){
    if(ind < 0){
        if(sum1 == 0) return 1;
        return 0;
    }
    if(dp[ind][sum1] != -1) return dp[ind][sum1];
    int nottake = 0, take = 0;

   if(arr[ind] <= sum1){take = junction(n, d, arr, sum1 - arr[ind], ind - 1, dp);}
    nottake = junction(n,d,arr,sum1,ind - 1, dp);

    return dp[ind][sum1] =  (take + nottake);
}
int findTargetSumWays(vector<int> &arr, int d) {
    int n = arr.size();
    int ts = 0;
    for(int i = 0; i < arr.size(); i++) ts += arr[i];
    if(((ts - d)&1 || ts - d < 0) == 1) return 0;
    vector<vector<int>> dp(arr.size(), vector<int>((ts-d)/2 + 1, -1));
    return junction(n, d, arr, (ts - d)/2, n - 1, dp);
}
};
