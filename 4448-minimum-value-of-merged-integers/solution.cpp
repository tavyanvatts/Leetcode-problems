class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX; 
        for(int i = 0; i < n - 1; i += 2){
            int mul = log10(abs(nums[i + 1])) + 1;
            int x = 1;
            while(mul){
                x *= 10;
                mul--;
            }          
            int num = nums[i]*x + nums[i + 1];
            mini = min(mini, num);
        }
        return mini;
    }
};
