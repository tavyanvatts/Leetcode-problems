class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> storage;
        int cnt;
        int longest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            storage.insert(nums[i]);
        }
        for(auto it : storage)
        {
            if(storage.find(it - 1) == storage.end())
            {
                cnt = 1;
            }
            else if(storage.find(it - 1) != storage.end())
            {
                cnt++;
            }
            longest = max(longest , cnt);
        }
        return longest;
    }
};
