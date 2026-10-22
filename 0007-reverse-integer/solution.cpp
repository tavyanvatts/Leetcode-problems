class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        int sign = 0;
        if(x < 0) sign = -1;
        else sign = 1;
        long long z = abs(1LL*x);
        while(z != 0){
            int dig = z%10;
            rev = rev*10 + dig;
            z /= 10;
        }
        if(rev > INT_MAX) return 0;
        else if(rev < INT_MIN) return 0;
        return rev*sign;
    }
};
