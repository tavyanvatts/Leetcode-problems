class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int n = nums.size();
        int maxdiff = INT_MIN;
        for(int i = 0; i < n - 1; i++)
            {
                maxdiff = max(abs(nums[i+1] - nums[i]) , maxdiff);
            }
        maxdiff = max(abs(nums[n - 1] - nums[0]) , maxdiff);
        return maxdiff;
    }
};
