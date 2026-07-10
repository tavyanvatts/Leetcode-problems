class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(hash[s[i]] < hash[s[i + 1]]) ans -= hash[s[i]];
            else ans += hash[s[i]];
        }
        ans += hash[s[n - 1]];
        return ans;
    }
};
