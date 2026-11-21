class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int al = 0;
        int bo = 0;
        vector<string> ans;
        for(int i = 0; i < rain.size() - 1; i++){
            if(rain[i] == 1 && rain[i + 1] == 1){
                if(al == bo){
                    al++;
                    ans.push_back("Alice");
                    continue;
                }
                else if(al < bo){
                    al++;
                    ans.push_back("Alice");
                    continue;
                }
                else if(bo < al){
                    bo++;
                    ans.push_back("Bob");
                    continue;
                }
            }
            else if(rain[i] == 1){
                bo++;
                ans.push_back("Bob");
            }
            else ans.push_back("None");
        }
        if(ans.size() < rain.size()){
            if(rain[rain.size() - 1] == 0) ans.push_back("None");
            else ans.push_back("Bob");
        }
        return ans;
    }
};
