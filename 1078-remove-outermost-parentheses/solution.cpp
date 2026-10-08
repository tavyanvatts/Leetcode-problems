class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        int start = -1;
        int end = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            if(cnt == 1 && start == -1) start = i;
            if(cnt == 0){
                end = i;
                s.erase(start, 1);
                end--;
                s.erase(end, 1);
                start = -1;
                end = -1;
                i-= 2;
            }
        }
        return s;
    }
};
