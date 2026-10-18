class Solution {
public:
    bool function(string& s, unordered_map<string, int>& hash, string ans, int ind, int len, vector<vector<int>> &dp) {
        if(ind == s.length()){
            return dp[ind][len] = len == s.length();
        }
        if(dp[ind][len] != -1) return dp[ind][len];
        bool res = false;
        ans += s[ind];
        if(hash.find(ans) != hash.end()){
            res = function(s, hash, "", ind + 1, len + ans.length(), dp) || function(s, hash, ans, ind + 1, len, dp);
        }
        if(!res) res = function(s, hash, ans, ind + 1, len, dp);

        return dp[ind][len] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int ind = 0;
        int len = 0;
        string ans = "";
        unordered_map<string, int> hash;
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        for (string it : wordDict) {
            hash[it]++;
        }
        return function(s, hash, ans, ind, len, dp);
    }
};
