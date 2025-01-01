class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cnt = 0;
        int cnt2 = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] == 1)
            {
                cnt++;
            }
            else if(nums[i] == 0)
            {
                if(cnt > cnt2)
                {
                    cnt2 = cnt;
                    cnt = 0;
                }
                cnt = 0;
            }
        }
        if(cnt > cnt2) return cnt;
        else{
            return cnt2;
        }
    }
};
