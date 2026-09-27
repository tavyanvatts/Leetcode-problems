class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans2;
        while (nums.size() > 0) {
            unordered_map<int, int> hash;
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++) {
                hash[nums[i]]++;
                if (hash[nums[i]] == 1) {
                    ans.push_back(nums[i]);
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }
            sort(ans.begin(), ans.end());
            ans2.insert(ans2.end(), ans.begin(), ans.end());
        }
        return ans2;
    }
};
