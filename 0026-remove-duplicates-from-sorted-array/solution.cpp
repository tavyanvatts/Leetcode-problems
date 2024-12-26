class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
         vector<int> temp;
            int cnt = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if(nums[i] != nums[i+1])
                {
                    temp.push_back(nums[i]);
                    cnt++;
                }
            }
            temp.push_back(nums[nums.size() - 1]);
            cnt += 1;
            for(int i = 0; i < temp.size(); i++)
            {
                nums[i] = temp[i];
            }
            return cnt;
    }
};
