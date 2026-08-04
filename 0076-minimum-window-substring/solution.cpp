class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char, int> freq;
        for(int i = 0; i < t.length(); i++){
            freq[t[i]]++;
        }
        int n = s.length();
        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int k = -1;
        int cnt = 0;
        while(r < n){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == t.length()){
                if(minlen > r - l + 1){
                    minlen = r - l + 1;
                    k = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) {cnt--;}
                l++;
            }
            
            r++;
        }
        return (k == -1) ? "" : s.substr(k, minlen);
    }
};
