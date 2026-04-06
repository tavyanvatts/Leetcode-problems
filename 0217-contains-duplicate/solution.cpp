class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mpp;
        for(int j = 0; j < nums.size(); j++){
            mpp[nums[j]]++;
            if(mpp[nums[j]] > 1) return true;
        }
        return false;
    }
};
