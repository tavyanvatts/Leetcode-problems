class Solution {
public:
bool function(string &s, unordered_map<string, int> &hash, int ind, string ans, int len, vector<vector<int>> &dp){
    if(ind == s.size()){
        return dp[ind][len] = len == s.length();
    }
    if(dp[ind][len] != -1) return dp[ind][len];

    ans += s[ind];
    bool res = false;
    if(hash.find(ans) != hash.end()){
        res = function(s, hash, ind + 1, "", len + ans.length(), dp);
    }
    if(!res){
        res = function(s, hash, ind + 1, ans, len, dp);
    }
    return dp[ind][len] = res;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> hash;
        int n = wordDict.size();
        for(int i = 0; i < n; i++){
            hash[wordDict[i]]++;
        }
        int ind = 0;
        string ans = "";
        int len = 0;
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
       return function(s, hash, ind, ans, len, dp);
    }
};
