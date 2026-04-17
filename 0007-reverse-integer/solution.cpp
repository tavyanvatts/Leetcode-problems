class Solution {
public:
    long long reverse(long long x) {
        long long rev = 0;
        if(x < 0){
            x = x*(-1);
            while (x > 0)
            {
            int l = x%10;
            rev = rev*10 + l;
            x = x/10;
            }
            rev = rev*(-1);
        }
        else if(x > 0){
            while (x > 0)
            {
            int l = x%10;
            rev = rev*10 + l;
            x = x/10;
            }
        }
        if(rev > INT_MAX || rev < INT_MIN) return 0;
        return rev;
    }
};
