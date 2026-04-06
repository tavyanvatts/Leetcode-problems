class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int> mpp;
        int i = 0;
        int len = 0;
        int n = s.length();
        int cnt = 0;
        if(n == 1) return 1;
        for(int j = 0; j < n; j++){
            mpp[s[j]]++;
            if(mpp[s[j]] == 1){
                len = max(len,j-i+1);
            }
            if(mpp[s[j]] > 1){
                len = max(len, j - i);
                while(s[i] != s[j]){
                    mpp[s[i]]--;
                    i++;
                }
                mpp[s[i]]--;
                i++;
            }
        }
        return len;
    }
};
