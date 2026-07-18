class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        if(((n-1)&1) == 0){
            return static_cast<long long>(static_cast<long long>(s) + static_cast<long long>(n - 1)/2*m - static_cast<long long>(n - 1)/2 + 1);
        }
        else{
            n++;
            return static_cast<long long>(static_cast<long long>(s) + static_cast<long long>(n - 1)/2*m - static_cast<long long>(n - 1)/2 + 1);
        }
    }
};
