class Solution {
public:
    void addvectorofsize(vector<vector<int>> &ans, vector<int> &temp, int size,
                        int start, vector<int> &nums) {
        if (temp.size() == size){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            addvectorofsize(ans, temp, size, i + 1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> temp;
            addvectorofsize(ans, temp, i, 0, nums);
        }
        return ans;
    }
};
