class Solution {
public:

int helper(string s, int i, long long num, int sign){
    if(i >= s.length() || !isdigit(s[i])) return (int)num*sign;
    int digit = s[i] - '0';
    num = num*10 + digit;
    if(sign*num >= INT_MAX) return INT_MAX;
    else if(sign*num <= INT_MIN) return INT_MIN;
    return helper(s, i+1, num, sign);
}

    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') i++;
        int sign = 1;
        if(s[i] == '-') {sign = -1; i++;}
        else if(s[i] == '+') i++;
        return helper(s, i, 0, sign);
    }
};
