class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            int rem = nums[i]%k;
            for(int j = i; j < n; j++){
                int curr = nums[j]%k;
                if(rem != curr){
                    i = j - 1;
                    break;
                }
                int len = j - i + 1;
                if((len - 1)*rem%k == 0){
                    ans = max(len , ans);
                }
            }
        }
        return ans;
    }
};
