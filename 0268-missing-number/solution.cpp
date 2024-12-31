class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum1 = 0;
        int sum2 = 0;
        int lar = nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > lar) lar = nums[i];
            sum1 += nums[i];
            sum2 += i;
        }
        if(sum1 == sum2) 
        {
            return n;
        }
        sum2 += lar;
        return (sum2 - sum1);

    }
};
