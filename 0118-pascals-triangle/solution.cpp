class Solution {
public:
vector<int> nthrow(int n){
    vector<int> ans(n + 1);
    ans[0] = 1;
    for(int i = 0; i < n; i++){
        ans[i + 1] = ans[i]*(n - i);
        ans[i + 1] = ans[i + 1]/(i + 1);
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
            ans[i] = nthrow(i);
        }
        return ans;
    }
};
