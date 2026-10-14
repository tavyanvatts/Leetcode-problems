class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int i = 9;
        if(9*num < sum) return "";
        string ans;
        while (ans.length() != num && i != 0) {
            while (i <= sum) {
                ans += i + '0';
                sum -= i;
            }
            i--;
        }
        while(ans.length() != num){
            ans += '0';
        }
        return ans;
    }
};
