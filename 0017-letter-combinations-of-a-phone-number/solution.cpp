class Solution {
public:
void letgen(string &digits, vector<string> &ans, string temp,vector<string> &alph, int si, int ai){
    if(si == digits.size()){
        ans.push_back(temp);
        return;
    }

    ai = digits[si] - '0' - 2; 
    for(int i = 0; i < alph[ai].length(); i++){
        temp += alph[ai][i];
        letgen(digits, ans, temp, alph, si + 1, ai);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        int si = 0;
        int ai = 0;
        vector<string> alph = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letgen(digits, ans, temp, alph, si, ai);
        return ans;
    }
};
