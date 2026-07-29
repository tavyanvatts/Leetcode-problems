class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int maxi = 0,ans=0;
        int j=0;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            if(mpp[s[i]] > maxi){
                maxi = mpp[s[i]];
            }
            int min = i-j+1 - maxi;
            while(min > k){
                mpp[s[j]]--;
                j++;
                maxi = max(maxi,mpp[s[j]]);
                min = i-j+1 - maxi;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
