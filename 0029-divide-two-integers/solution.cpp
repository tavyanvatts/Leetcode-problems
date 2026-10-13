class Solution {
public:
    int divide(int num, int din) {
        int sign = 1;
        if(num > 0 && din > 0) sign = 1;
        else if(num < 0 && din < 0) sign = 1;
        else sign = -1;
        long long long_num = abs((long long)num);
        long long long_din = abs((long long)din);
        int i = 0;
        long long quotient = 0;
        while (long_num >= long_din) {
            i = 0;
            if(long_num < long_din) break;
            while ((long_din << i) <= long_num) {
                i++;
            }
            i--;
            quotient += (1LL << i);
            long_num -= (long_din << i);
        }
        if(sign == -1){
            quotient++;
            quotient = 1 - quotient;
        }
        if(quotient > INT_MAX) return INT_MAX;
        if(quotient < INT_MIN) return INT_MIN;
        return quotient;
    }
};
