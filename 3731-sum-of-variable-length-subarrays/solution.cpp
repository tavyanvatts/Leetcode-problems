class Solution {
public:
    int subarraySum(vector<int>& nums) 
    {
        int sum = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
            {
                start = max(0 , i - nums[i]);
                for(int j = start; j < i + 1; j++)
                    {
                        sum += nums[j];
                    }
            }
        return sum;
    }
};
