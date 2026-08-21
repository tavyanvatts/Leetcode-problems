class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++){
            int cnt = 0;
            int temp = i;
            while(temp > 0){
                bool k = (temp&1);
                cnt += k;
                temp = temp>>1 ;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
