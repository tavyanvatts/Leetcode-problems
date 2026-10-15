class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            set<int> hash;
            for(int j = i; j < nums.size(); j++){
                hash.insert(nums[j]);
                int n = hash.size();
                ans += n*n;
            }
        }
        return ans;
    }
};
