class Solution {
public:
long long ds(string &s, string &t, int ind1, int ind2, vector<vector<int>> &dp){
    if(ind2 == t.length()) return dp[ind1][ind2] = 1;
    if(ind1 == s.length())return dp[ind1][ind2] = 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s[ind1] == t[ind2]){
        return dp[ind1][ind2] = ds(s,t,ind1+1,ind2+1, dp) + ds(s,t,ind1+1,ind2, dp);
    }
    else return dp[ind1][ind2] = ds(s,t,ind1+1, ind2, dp);
}
    int numDistinct(string s, string t) {
        int ind1 = 0, ind2 = 0;
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
        return ds(s, t, ind1, ind2, dp);
    }
};
