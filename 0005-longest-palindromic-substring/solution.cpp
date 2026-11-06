class Solution {
public:

string lengthcalc(int l, int r, string &s){
    while((l >= 0 && r < s.size()) && s[l] == s[r]){
        l--;
        r++;
    }
    l++;
    r--;
    return s.substr(l, r - l + 1);
}
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            string o = lengthcalc(i, i, s);
            string e = lengthcalc(i, i + 1, s);
            if(ans.size() < max(o.size(), e.size())){
                if(o.size() > e.size()) ans = o;
                else ans = e;
            }
        }
        return ans;
    }
};
