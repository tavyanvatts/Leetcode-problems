class Solution {
public:
int lcs(string &s, string &s2, int ind1, int ind2, vector<vector<int>>& dp){
    if(ind1 == s.length() || ind2 == s2.length()){
        return 0;
    }
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s[ind1] == s2[ind2]){
        return dp[ind1][ind2] =  1 + lcs(s, s2, ind1 + 1, ind2 + 1, dp);
    }
    else{
        return dp[ind1][ind2] = max(lcs(s, s2, ind1 + 1, ind2, dp), lcs(s, s2, ind1, ind2 + 1, dp));
    }
}
    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(), s.rend());
        vector<vector<int>> dp(s.length() + 1, vector<int>(s2.length() + 1, -1));
        return lcs(s, s2, 0, 0, dp);
    }
};
