class Solution {
public:
    int calculateScore(int a, int b) {
        int k = __builtin_popcount(a);
        int t = __builtin_popcount(b);
        if(k >= t) return k*t;
        return t/k;
    }
};
