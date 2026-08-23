class Solution {
public:
    string tobin(int n) {
        if(n == 0) return "00000000";
        string res;
        while (n > 0) {
            if (n % 2 == 1)
                res += '1';
            else
                res += '0';
            n = n / 2;
        }
        while(res.length() < 8) res += '0';
        reverse(res.begin(), res.end());
        return res;
    }
    bool isPalindromic(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            ans += tobin(s[i]);
        }
        string t(ans.rbegin(), ans.rend());
        return (ans == t) ? 1 : 0;
    }
};
