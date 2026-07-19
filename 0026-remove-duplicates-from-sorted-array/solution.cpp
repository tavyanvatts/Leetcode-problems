class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int u = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[j]){
                continue;
            }
            else if(nums[i] != nums[j]){
                swap(nums[i], nums[u]);
                u++;
                j++;
            }
        }
        return u;
    }
};
