class Solution {
public:
    int function(string& s, int start, int n, vector<int>& dp,vector<vector<bool>> &pal) {

        if (start == n)
            return 0;
        if (dp[start] != -1)
            return dp[start];
        int cut = 0;
        int mini = INT_MAX;
        for (int end = start; end < n; end++) {
            if (pal[start][end]) {
                cut = 1 + function(s, end + 1, n, dp, pal);

                mini = min(cut, mini);
            }
        }
        return dp[start] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
                    pal[i][j] = true;
            }
        }
        vector<int> dp(n, -1);
        return function(s, 0, n, dp, pal) - 1;
    }
};
