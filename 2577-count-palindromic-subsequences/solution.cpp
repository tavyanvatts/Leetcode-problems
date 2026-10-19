class Solution {
public:
    int mod = 1e9 + 7;
    int countPalindromes(string s) {
        int n = s.length();
        vector<vector<vector<long long>>> pre(
            n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        vector<long long> count(10, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                for (int x = 0; x < 10; x++) {
                    for (int y = 0; y < 10; y++) {
                        pre[i][x][y] = pre[i - 1][x][y];
                    }
                }
            }
            int curr = s[i] - '0';
            if (i > 0) {
                for (int j = 0; j < 10; j++) {
                    pre[i][j][curr] = (pre[i][j][curr] + count[j]) % mod;
                }
            }
            count[curr]++;
        }
        vector<vector<vector<long long>>> suff(
            n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        count.assign(10, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                for (int x = 0; x < 10; x++) {
                    for (int y = 0; y < 10; y++) {
                        suff[i][x][y] = suff[i + 1][x][y];
                    }
                }
            }
            int curr = s[i] - '0';
            if (i < n - 1) {
                for (int j = 0; j < 10; j++) {
                    suff[i][curr][j] = (suff[i][curr][j] + count[j]) % mod;
                }
            }
            count[curr]++;
        }

        long long tp = 0;

        for (int i = 2; i < n - 2; i++) {
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
    long long c = (pre[i - 1][x][y] * suff[i + 1][y][x])%mod;
                    tp = (tp + c) % mod;
                }
            }
        }
        return tp;
    }
};
