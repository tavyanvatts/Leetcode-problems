class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n  - 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                swap(nums[low], nums[i]);
                low++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[high]);
                high--;
                i--;
            }
            if(i >= high){
                break;
            }
        }
    }
};
