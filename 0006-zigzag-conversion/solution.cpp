class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
         vector<vector<char>> ans(numRows, vector<char>(1000, ' '));
         int ind = 0;
            int i = 0, j = 0;
         while(ind < s.length()){
            while(i < numRows && ind < s.length()){
                ans[i][j] = s[ind];
                ind++;
                i++;
            }
            i--;
            i--;
            j++;
            while(i >= 0 && ind < s.length()){
                ans[i][j] = s[ind];
                i--;
                j++;
                ind++;
            }
            i++;
            i++;
            j--;
         }
         string k;
         for(int i = 0; i < numRows; i++){
            for(int j = 0; j < 1000; j++){
                if(ans[i][j] != ' ') k += ans[i][j];
            }
         }
         return k;
    }
};
