class Solution {
public:
void sumfinder(vector<int>& left, int k, int sum, int ind, vector<int>& ans){
    if(k == 0){
        ans.push_back(sum);
        return;
    }
    if(ind == left.size()){
        if(k != 0){
            return;
        }
    }
sumfinder(left, k - 1, sum + left[ind], ind + 1, ans);
sumfinder(left, k, sum, ind + 1, ans);

}
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int ts = 0;
        for(int i = 0; i < nums.size(); i++){
            ts += nums[i];
        }
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());
        vector<vector<int>>arrl(n+1),arrr(n+1);
        for(int i=0; i<=n; i++){
            vector<int>ans;
            sumfinder(left,i,0,0,ans);
            arrl[i] = ans;
        }
        for(int i=0; i<=n; i++){
            vector<int>ans;
            sumfinder(right,i,0,0,ans);
            arrr[i] = ans;
            sort(arrr[i].begin(), arrr[i].end());
        }
        int mini = INT_MAX;
        for(int i = 0; i <= n; i++){
            for(auto c : arrl[i]){
                int k = n - i;
                int target = ts/2 - c;
               auto it = lower_bound(arrr[k].begin(), arrr[k].end(), target);
               if(it != arrr[k].end()){
                mini = min(mini,abs(ts-2*(c+*it)));
               }
               if(it != arrr[k].end() && *it != target){
                mini = min(mini,abs(ts-2*(c+*it)));
                if(it != arrr[k].begin())--it;
                mini = min(mini,abs(ts-2*(c+*it)));
               }
            }
        }
        return mini;
    }
};
