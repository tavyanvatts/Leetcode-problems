class Solution {
public:
    string leftrotate(string &s) {
        s += s[0];
        s.erase(0, 1);
        return s;
    }
    int minOperations(string s) {
        int n = s.length();
        int minops = INT_MAX;
        int cnt = 0;
        while (cnt != n) {
            if(cnt != 0){leftrotate(s);}
            int ops = 0;
            int l = 0;
            int r = n - 1;
            while (l < r) {
                ops += min((int)abs(s[r] - s[l]), 26 - (int)abs(s[r] - s[l]));
                l++;
                r--;
            }
            minops = min(minops, ops + cnt);
            cnt++;
        }
        return minops;
    }
};
