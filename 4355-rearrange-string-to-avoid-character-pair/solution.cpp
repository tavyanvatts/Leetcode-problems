class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int  low = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == y){
                swap(s[i], s[low]);
                low++;
            }
        }
        return s;
    }
};
