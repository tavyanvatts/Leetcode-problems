class Solution {
public:

void generatevalidstrings(vector<string> &ans, string s, int n){
    if(s.length() == n) {
        ans.push_back(s);
        return;
    }
    if(s[s.length() - 1] == '0') {s += '1';
    generatevalidstrings(ans, s, n);
    }
    else{
        s += '1';
        generatevalidstrings(ans, s, n);
        s.pop_back();
        s += '0';
        generatevalidstrings(ans, s, n);
    }

}

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s1 = "0";
        string s2 = "1";
        generatevalidstrings(ans, s1, n);
        generatevalidstrings(ans, s2, n);
        return ans;
    }
};
