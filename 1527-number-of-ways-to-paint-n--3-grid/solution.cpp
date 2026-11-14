class Solution {
public:
    int numOfWays(int n) {
        long long last1 = 6, last2 = 6;
        long long curr1 = 0, curr2  = 0;
        int mod = 1e9 + 7;
        for(int i = 1; i < n; i++){
            curr1 = last1*3 + last2*2;
            curr2 = last1*2 + last2*2;
            last1 = curr1%mod;
            last2 = curr2%mod;
        }
        return (last1 + last2)%mod;
    }
};
