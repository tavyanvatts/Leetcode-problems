class Solution {
public:
    void comgen(vector<int>& candidates, int target, vector<vector<int>>& ans,
                vector<int> temp, int index) {
        if (index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            comgen(candidates, target - candidates[index], ans, temp, index);
            temp.pop_back();
        }
        comgen(candidates, target, ans, temp, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        comgen(candidates, target, ans, temp, index);
        return ans;
    }
};
