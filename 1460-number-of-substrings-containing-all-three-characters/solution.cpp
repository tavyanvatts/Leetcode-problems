class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> freq;
        int ans = 0;
        while(r < s.length()){
            freq[s[r]]++;
            while(freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0){
                ans += s.length() - r;
                freq[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
