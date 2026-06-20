class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]]++;
            if(hashmap[nums[i]] == nums.size()/3 + 1){
                ans.push_back(nums[i]);
        }
        }
        return ans;
    }
};
