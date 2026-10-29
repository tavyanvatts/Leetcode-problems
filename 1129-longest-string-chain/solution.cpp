class Solution {
public:

bool check(string &s1, string &s2){
    if(s2.size() - s1.size() != 1) return false;
    int first = 0;
    int second = 0;
    while(second < s2.size()){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            second++;
        }
    }
            if(first == s1.size() && second == s2.size()) return true;
        return false;
}
    int longestStrChain(vector<string>& words) {
         int n = words.size();
         vector<int> dp(n, 1);
         int maxi = 1;
         sort(words.begin(),words.end(), [](auto &a, auto&b){
            return b.size() > a.size();
         });
         for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(check(words[prev], words[i]) && dp[i] < dp[prev] + 1) dp[i] = dp[prev] + 1;
            }
            maxi = max(dp[i], maxi);
         }
         return maxi;
    }
};
