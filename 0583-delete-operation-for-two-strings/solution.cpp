class Solution {
public:
    int lcs(string& w1, string& w2, int ind1, int ind2,
            vector<vector<int>>& dp) {
        if (ind1 == w1.length() || ind2 == w2.length())
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (w1[ind1] == w2[ind2]) {
            return dp[ind1][ind2] = 1 + lcs(w1, w2, ind1 + 1, ind2 + 1, dp);
        } else
            return dp[ind1][ind2] = max(lcs(w1, w2, ind1, ind2 + 1, dp),
                                        lcs(w1, w2, ind1 + 1, ind2, dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        return word1.length() +  word2.length() -
               2*lcs(word1, word2, 0, 0, dp);
    }
};
