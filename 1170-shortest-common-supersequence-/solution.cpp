class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for(int i = 1; i <= s1.length(); i++){
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        int i = s1.length(), j = s2. length();
        string ans = "";
        while(i > 0 && j > 0){
            if(s1[i - 1] != s2[j - 1]){
                if(dp[i][j - 1] == dp[i - 1][j]){
                ans += s1[i - 1];
                i--;
            }
            else if(dp[i][j - 1] > dp[i -1][j]){
                ans += s2[j - 1];
                j--;
            }
            else{
                ans += s1[i - 1];
                i--;
            }}
            else{
                ans += s1[i - 1];
                i--;
                j--;
            }
        }
        while(i > 0){ans += s1[i - 1]; i--;}
        while(j > 0){ans += s2[j - 1]; j--;}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
