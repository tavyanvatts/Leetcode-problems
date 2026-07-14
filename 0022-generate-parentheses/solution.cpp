class Solution {
public:

void generatevalidstrings(vector<string> &ans,string s,int o,int c,int n){
    if(o - c < 0) return;
    if(o > n || c > n) return;
    if(o + c == 2*n){
        ans.push_back(s);
        return;
    }
        generatevalidstrings(ans, s + '(', o + 1, c, n);
        
        generatevalidstrings(ans, s + ')', o, c + 1, n);
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        int o = 1;
        int c = 0;
        generatevalidstrings(ans, s, o, c, n);
        return ans;
    }
};
