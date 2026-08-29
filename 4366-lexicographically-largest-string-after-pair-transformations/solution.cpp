class Solution {
public:
string function(int n){
    string ans = "";
    char ch = 'a';
    while(n > 0){
        if(ch == 'z'){
            ans.append(n,'z');
            break;
        }
        if((n&1) == 1){
            ans += ch;
        }
        ch++;
        n = n/2;
    }
    return string(ans.rbegin(), ans.rend());
}
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(function(nums[i]));
        }
        return ans;
    }
};
