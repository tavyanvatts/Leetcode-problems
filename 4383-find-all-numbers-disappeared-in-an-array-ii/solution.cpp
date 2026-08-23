class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<vector<int>> ans;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        int l = lower;
        int r = lower;
        while(r <= upper){
            if(hash.find(r) == hash.end()){
                r++;
            }
            else{
                if(l <= r - 1){ans.push_back({l, r - 1});}
                r++;
                l = r;
            }
        }
        if(r - l + 1 != 1){
            ans.push_back({l , r - 1});
        }
        return ans;
    }
};
