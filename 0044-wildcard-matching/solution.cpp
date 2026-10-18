class Solution {
public:

bool matcher(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp){
    if(ind1 < 0 && ind2 < 0) return true;
    if(ind2 < 0 && ind1 >= 0) return false;
    if(ind1 < 0 && ind2 >= 0){
        for(int i = 0; i <= ind2; i++) if(p[i] != '*') return false;
        return true;
    }
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s[ind1] == p[ind2] || p[ind2] == '?'){
        return dp[ind1][ind2] =  matcher(s, p, ind1 - 1, ind2 - 1, dp);
    }
    if(p[ind2] == '*'){
        return dp[ind1][ind2] = matcher(s, p, ind1 - 1, ind2, dp) || matcher(s, p, ind1, ind2 - 1, dp);
    }
    else{
        return dp[ind1][ind2] = false;
    }
}
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        int ind1 = m - 1;
        int ind2 = n - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return matcher(s,p,ind1,ind2, dp);
    }
};
