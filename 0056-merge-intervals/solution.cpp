class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= merged[merged.size() - 1][1]){
                merged[merged.size() - 1][1] = max(merged[merged.size() - 1][1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
