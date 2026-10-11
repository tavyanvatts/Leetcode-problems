class Solution {
public:
    bool threeFibonacciSum(int n) {
        if((n&1) == 1) return false;
        int a = 0;
        int b = 1;
        int c = 0;
        while(c < n/2){
            c = a + b;
            a = b;
            b = c;
        }
        if(c == n/2) return true;
        return false;
    }
};
