class Solution {
public:

void function(vector<string> &ans, int n, int sum, string s){
    if(sum < 0) return;
    if(n == 0){
        if(sum == 0){ans.push_back(s);}
        return;
    }
    if(n > 0){
        function(ans, n - 1, sum + 1, s + '(');
    }
    function(ans, n - 1, sum - 1, s + ')');
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        function(ans, 2*n, 0, s);
        return ans;
    }
};
