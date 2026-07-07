class Solution {
public:
    string reverseWords(string s) {
        stack<string> store;
        string word = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(word != ""){store.push(word);}
                word = "";
            }
            else word += s[i];
        }
        store.push(word);
        string ans;
        while(!store.empty()){
            ans += store.top();
            ans += ' ';
            store.pop();
        }
        while(ans[0] == ' ' || ans.back() == ' '){
            if(ans.back() == ' ') ans.pop_back();
            else ans.erase(0,1);
        }
        return ans;
    }
};
