class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        string ans;
            int carry = 0;
        while (n >= 0 && m >= 0) {
            if (a[n] == '0' && b[m] == '0') {
                if (carry == 0)
                    ans += '0';
                else {
                    ans += '1';
                    carry = 0;
                }
            } else if (a[n] == '0' || b[m] == '0') {
                    if(carry == 0) {ans += '1';}
                    else {
                        ans += '0';
                    }
            } else {
                    if(carry == 0) ans += '0';
                    else ans += '1';
                    carry = 1;
            }
            n--;
            m--;
        }
        while (n >= 0) {
            if(carry == 1){
                if(a[n] == '0'){
                    ans += '1';
                    carry = 0;
                }
                else{
                    ans += '0';
                }
            }
            else ans += a[n];
            n--;
        }
        while (m >= 0) {
            if(carry == 1){
                if(b[m] == '0'){
                    ans += '1';
                    carry = 0;
                }
                else{
                    ans += '0';
                }
            }
            else ans += b[m];
            m--;
        }
        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
