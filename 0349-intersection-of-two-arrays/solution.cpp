class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int , pair<int, int>> hashmap;
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++)
        {
            hashmap[nums1[i]].first++;
        }
        for(int j = 0; j < nums2.size(); j++)
        {
            hashmap[nums2[j]].second++;
        }
        for(auto it : hashmap)
        {
            if(it.second.first > 0 && it.second.second > 0) ans.push_back(it.first);
        }
        return ans;
    }
};
