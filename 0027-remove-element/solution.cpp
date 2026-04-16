class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        vector<int> ans;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) {
                swap(nums[j], nums[i]);
                i = j;
                j++;
                k++;
            }
        }
        return k;
    }
};
