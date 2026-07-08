class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int oddi = -1;
        for(int i = n - 1; i >= 0; i--){
            int t = num[i] - '0';
            if((t&1) == 1) {oddi = i;
            break;
            }
        }
        return (oddi != -1) ? num.substr(0, oddi + 1) : "";
    }
};
