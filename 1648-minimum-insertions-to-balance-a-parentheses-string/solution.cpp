class Solution {
public:
    int minInsertions(string s) {
        int unop = 0;
        int insertions = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') unop++;
            else{
                if(unop > 0) unop--;
                else if(unop <= 0) insertions++;
                if(i +1 < s.length() && s[i + 1] == ')'){i++;}
                else insertions++;
            }
        }
        return 2*unop + insertions;
    }
};
