class Solution {
public:
    string reverseByType(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j){
            if(islower(s[i]) && islower(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(islower(s[i])){
                j--;}
            
            else i++;
        }
        i = 0;
        j = s.length() - 1;
        while(i <= j){
            if(!isalpha(s[i]) && !isalpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(isalpha(s[i])){
                i++;
            }
            else j--;
        }
        return s;
    }
};
