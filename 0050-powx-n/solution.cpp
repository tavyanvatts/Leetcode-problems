class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;
        if(nn < 0) nn = nn*(-1);
while(nn){        if((nn&1) == 1){
            ans = ans*x;
            nn = nn - 1;
        }
        else{
            x = x*x;
            nn = nn/2;
        }}
        if(n < 0) return 1/ans;
        return ans;
    }
};
