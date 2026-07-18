class Solution {
public:
    void comgen(vector<int>& candidates, int target, vector<vector<int>>& ans,
                vector<int> temp, int index) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            target -= candidates[index];
            int i = index + 1;
            comgen(candidates, target, ans, temp, i);
            temp.pop_back();
            target += candidates[index];
        }
        int i = index + 1;
        while ( i < candidates.size() && candidates[i] == candidates[i - 1])
            i++;
        comgen(candidates, target, ans, temp, i);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        comgen(candidates, target, ans, temp, index);
        return ans;
    }
};
