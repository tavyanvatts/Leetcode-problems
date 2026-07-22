class Solution {
public:
void pargen(int start,vector<vector<string>> &ans,vector<string> temp,string &s){
    if(start == s.length()){
        ans.push_back(temp);
        return;
    }
    for(int i = start; i < s.length(); i++){
        string sub = s.substr(start, i - start + 1);
        string revsub(sub.rbegin(), sub.rend());
        if(sub == revsub){
            temp.push_back(sub);
            pargen(i + 1, ans, temp, s);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int start = 0;
        pargen(start, ans, temp, s);
        return ans;
    }
};
