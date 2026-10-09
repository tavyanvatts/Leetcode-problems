class Solution {
public:
    string function(int n) {
        int cnt = 0;
        string addi = "";
        while (n != 1) {
            if (n % 2 == 0) {
                cnt += 1;
                n /= 2;
            } else if (n % 2 == 1) {
                addi += 'a' + cnt;
                n--;
            }
        }
        char h = 'a' + cnt;
        if(h == '{') addi += "zz";
        else addi += h;
        reverse(addi.begin(), addi.end());
        return addi;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(function(nums[i]));
        }
        return ans;
    }
};
