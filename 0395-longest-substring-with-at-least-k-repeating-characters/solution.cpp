class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int maxlen = INT_MIN;
        for(int i = 1; i <= 26; i++){
        unordered_map<char, int> hash;
            int l = 0;
            int r = 0;
            int unique = 0;
            int cnt = 0;
            while(r < n){
                if(hash[s[r]] == 0){
                    unique++;
                }
                if(hash[s[r]] == k - 1) cnt++;
                hash[s[r]]++;
                while(unique > i){
                    if(hash[s[l]] == 1) unique--;
                    if(hash[s[l]] == k) cnt--;
                    hash[s[l]]--;
                    l++;
                }
                if(unique == i && cnt == i){
                    maxlen = max(maxlen, r - l + 1);
                }
                r++;
            }
        }
        return (maxlen == INT_MIN) ? 0 : maxlen;
    }
};
