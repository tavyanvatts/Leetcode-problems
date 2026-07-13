class Solution {
public:
const int mod = 1e9 + 7;
long long power(long long x, long long y){
    long long ans = 1;
    while(y){if(y%2 == 0){
        x = (x*x)%mod;
        y = y/2;
    }
    else{
        ans = (ans*x)%mod;
        y = y - 1;
    }}
    return ans;
}
    int countGoodNumbers(long long n) {
        if(n%2 == 0){
            return (power(5, n/2)*power(4, n/2))%mod;
        }
        return (power(5, n/2 + 1)*power(4, n/2))%mod;
    }
};
