class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map <int , int> hashmap;
       for(int i = 0; i < nums.size(); i++)
       {
        int t  = target - nums[i] ;
        if(hashmap.find(t) == hashmap.end())
        {
            hashmap[nums[i]] = i;
        }
          else if(hashmap.find(t) != hashmap.end())
            {
                vector <int> A;
                A.push_back(i);
                A.push_back(hashmap[t]);
                return A;
            }
       } 
       return {};   
    }
};
