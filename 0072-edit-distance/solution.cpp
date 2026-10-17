class Solution {
public:

int lms(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
    if(i == w1.length()) return w2.length() - j;
    if(j == w2.length()) return w1.length() - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(w1[i] == w2[j])
    {return dp[i][j] = lms(w1, w2, i + 1, j + 1, dp);}
    else return dp[i][j] = min(min(1 + lms(w1,w2, i + 1, j, dp), 1 + lms(w1,w2,i + 1, j+1, dp)), 1 + lms(w1, w2, i, j + 1, dp));

}
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int extra = 0;
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return lms(word1, word2, i, j, dp);
    }
};
