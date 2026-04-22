class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(hash.find(target - nums[i]) != hash.end()){
                return {i, hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
