class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1) return s.length();
        int j = 0;
        unordered_map<char,int> hash;
        int maxi = 0;
        for(int i = 0; i < s.length(); i++){
            hash[s[i]]++;
            if(hash[s[i]] > 1){
                maxi = max(maxi, i - j);
                while(s[j] != s[i]){
                    hash[s[j]]--;
                    j++;
                }
                hash[s[j]]--;
                j++;
            }
            if(hash[s[i]] == 1){
                maxi = max(maxi, i - j + 1);
            }
        }
        return maxi;
    }
};
