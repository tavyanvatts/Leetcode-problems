class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < n) {
            int k = n - 1;
            int j = i + 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] == 0) {
                    int t = nums[j];
                    int v = nums[k];
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    while (nums[j] == t && j < k) {
                        j++;
                    }
                    while (nums[k] == v && k > j) {
                        k--;
                    }
                }
            }
            int s = nums[i];
            while (i < n && nums[i] == s) {
                i++;
            }
        }
        return ans;
    }
};
