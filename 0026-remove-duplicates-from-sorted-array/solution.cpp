class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int u = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[j]) continue;
            else if(nums[i] != nums[j]){
                u++;
                swap(nums[i], nums[j + 1]);
                j++;
            }
        }
        return u;
    }
};
