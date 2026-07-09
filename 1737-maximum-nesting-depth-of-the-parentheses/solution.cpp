class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int sum = 0;
        int maxdep = INT_MIN;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') sum++;
            maxdep = max(maxdep, sum);
            if(s[i] == ')') sum--;
        }
        return maxdep;
    }
};
