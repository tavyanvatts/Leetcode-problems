class Solution {
public:
void subgen(vector<int>& nums,vector<vector<int>>& ans,vector<int> temp,int index){
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    subgen(nums, ans, temp, index + 1);
    temp.pop_back();
    int i = index + 1;
    while(i < nums.size() && nums[i] == nums[i - 1])i++;
    subgen(nums, ans, temp, i);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        sort(nums.begin(), nums.end());
        subgen(nums, ans, temp, index);
        return ans;
    }
};
