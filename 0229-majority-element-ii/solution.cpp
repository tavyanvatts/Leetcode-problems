class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;
        map<int , int> hashmap;
        for(int i = 0; i < nums.size(); i++)
        {
            hashmap[nums[i]]++;
        }
        for(auto it : hashmap)
        {
            if(it.second > nums.size()/3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
