class Solution {
public:
    string intToRoman(int num) {
        string ans;
        unordered_map<int, char> hash;
        hash[1] = 'I';
        hash[5] = 'V';
        hash[10] = 'X';
        hash[50] = 'L';
        hash[100] = 'C';
        hash[500] = 'D';
        hash[1000] = 'M';
        int i = 1;
        while (num > 0) {
            int dig = num % 10;
            int t;
            if (dig == 9) {
                t = dig * i;
                switch (i) {
                case 1:
                    ans += "XI";
                    break;
                case 10:
                    ans += "CX";
                    break;
                case 100:
                    ans += "MC";
                    break;
                }
            } else if (dig == 4) {
                t = dig * i;
                switch (i) {
                case 1:
                    ans += "VI";
                    break;
                case 10:
                    ans += "LX";
                    break;
                case 100:
                    ans += "DC";
                    break;
                }
            } else {
                t = dig * i;
                string d;
                while (t > 0) {
                    if (t >= 1000) {
                        d += hash[1000];
                        t -= 1000;
                    } else if (t >= 500) {
                        d += hash[500];
                        t -= 500;
                    } else if (t >= 100) {
                        d += hash[100];
                        t -= 100;
                    } else if (t >= 50) {
                        d += hash[50];
                        t -= 50;
                    } else if (t >= 10) {
                        d += hash[10];
                        t -= 10;
                    } else if (t >= 5) {
                        d += hash[5];
                        t -= 5;
                    } else if (t >= 1) {
                        d += hash[1];
                        t -= 1;
                    }
                }
                    reverse(d.begin(), d.end());
                    ans += d;
            }
            num /= 10;
            i *= 10;
        }
        string a(ans.rbegin(), ans.rend());
        return a;
    }
};
