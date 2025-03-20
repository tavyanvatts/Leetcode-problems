class Solution {
public:
int divsum(vector<int>& nums, int threshold, int div)
{
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum = sum + ceil((double)nums[i]/(double)div) ;
    }
    if(sum <= threshold) return 1;
    else{return 0;}
}
int maxele(vector<int>& nums)
{
    int maxi = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > maxi)
        {
            maxi = nums[i];
        }
    }
    return maxi;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxele(nums);
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int divmid = divsum(nums, threshold, mid);
            if(divmid == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else{low = mid + 1;}
        }
        return ans;
    }
};
