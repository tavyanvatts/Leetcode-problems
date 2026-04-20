class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxsum = 0;
        int cursum = 0;
        for(int i = 0; i < nums.size(); i++){
            cursum += nums[i];
            if(nums[i] == 0){
                maxsum = max(maxsum, cursum);
                cursum = 0;
            }
        }
        maxsum = max(maxsum, cursum);
        return maxsum;
    }
};
