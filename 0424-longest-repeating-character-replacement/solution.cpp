class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> hash;
        int maj = INT_MIN;
        int maxi = INT_MIN;
        int n = s.length();
        while(r < n){
            hash[s[r]]++;
            if(hash[s[r]] > maj){
                maj = hash[s[r]];
            }
            if(r - l + 1 - maj > k){
                hash[s[l]]--;
                l++;
            }
            maxi = max(r - l + 1, maxi);
            r++;
        }
        return maxi;
    }
};
