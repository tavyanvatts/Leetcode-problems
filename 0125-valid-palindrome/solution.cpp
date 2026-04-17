class Solution {
public:
    bool isPalindrome(string s) {
        string news = "";
        for(int i = 0; i < s.length(); i++){
            if(isalnum(s[i])){
                news += tolower(s[i]);
            }
        }
        int i = 0;
        while(i < news.length()/2){
            if(news[i] != news[news.length() - i - 1]){
                return false;
            }
            i++;
        }
        return true;
    }
};
