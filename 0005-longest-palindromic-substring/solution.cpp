class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 1;
        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            int oddlen = expander(s, i - 1, i + 1);
            int evenlen = expander(s, i, i+1);
            maxlen = max(oddlen, evenlen);
            
            if(maxlen > end - start)
            {start = i - maxlen/2;
            if(evenlen > oddlen) start = i - maxlen/2 + 1;
            end = i + maxlen/2;}
        }
        return s.substr(start, end - start + 1);
    }
    int expander(string s, int l, int r){
        int n = s.length();
        if(l < 0 || r > n - 1) return r - l - 1;
        while(s[l] == s[r]){
            l--;
            r++;
            if(l < 0 || r > n - 1) return r - l - 1;
        }
        return r - l - 1;
    }
};
