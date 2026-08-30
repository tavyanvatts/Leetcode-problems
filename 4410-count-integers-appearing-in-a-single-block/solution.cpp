class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int special = 0;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){hash[nums[i]]++;}
            if(i > 0){
                if(nums[i] != nums[i - 1]){
                    hash[nums[i]]++;
                }
            }
        }
        for(auto p : hash){
            if(p.second == 1) special++;
        }
        return special;
    }
};
