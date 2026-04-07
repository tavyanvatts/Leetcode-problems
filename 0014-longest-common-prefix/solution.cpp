class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minilen = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            minilen = min((int)strs[i].size(), minilen);
        }
        string ans = "";
        bool ok = false;
        for(int i = 0; i < minilen; i++){
            for(int j = 0; j < strs.size() - 1; j++){
                if(strs[j][i] != strs[j + 1][i]){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
            ans += strs[strs.size() - 1][i];
        }
        return ans;
    }
};
