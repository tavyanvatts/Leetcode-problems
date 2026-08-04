class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        int l = 0;
         int r = 9;
         vector<string> ans;
         string temp = s.substr(0,10);
         unordered_map<string, int> hash;
         while(r < s.length()){
            hash[temp]++;
            if(hash[temp] == 2)ans.push_back(temp);
            r++;
            temp += s[r];
            temp.erase(0,1);
            l++;
         }
         return ans;
    }
};
