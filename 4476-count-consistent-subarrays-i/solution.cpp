class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            int mini = INT_MAX;
            int a = nums[i];
            for(int j = i; j < nums.size(); j++){
                mini = min(mini, nums[j]);
                a = (a&nums[j]);
                if(a == mini) cnt++;
            }
        }
        return cnt;
    }
};
