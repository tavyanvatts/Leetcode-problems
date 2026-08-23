class Solution {
public:
vector<int> primef(int n){
    vector<int> pf;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) pf.push_back(i);
        while(n%i == 0){
            n = n/i;
        }
    }
    if(n != 1) pf.push_back(n);
    return pf;
}
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r < nums.size()){
            vector<int> d = primef(nums[r]);
            for(int i = 0; i < d.size(); i++) hash[d[i]]++;
            while(hash.size() > k){
                vector<int> t = primef(nums[l]);
                for(int j = 0; j < t.size(); j++){
                    hash[t[j]]--;
                    if(hash[t[j]] == 0) hash.erase(t[j]);
                }
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};
