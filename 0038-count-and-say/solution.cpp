class Solution {
public:
    string RLE(string s) {
        if (s == "1")
            return "11";
        else {
            int cnt = 0;
            string ans;
            for (int i = 0; i < s.length() - 1; i++) {
                cnt++;
                if (s[i] != s[i + 1]) {
                    ans += (cnt + '0');
                    ans += s[i];
                    cnt = 0;
                }
            }
            if (s[s.length() - 1] == s[s.length() - 2]) {
                cnt++;
                ans += (cnt + '0');
                ans += s[s.length() - 1];
                return ans;
            }
            if (s[s.length() - 1] != s[s.length() - 2]) {
                ans += '1';
                ans += s[s.length() - 1];
                return ans;
            }
        }
        return "0";
    }
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return RLE(countAndSay(n - 1));
    }
};
