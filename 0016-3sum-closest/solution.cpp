class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                if(abs(target - nums[i] - nums[l] - nums[r]) < abs(target - ans)) ans = nums[i] + nums[l] + nums[r];
                if(nums[i] + nums[l] + nums[r] < target) l++;
                else if(nums[i] + nums[r] + nums[l] > target) r--;
                else return nums[i] + nums[l] + nums[r];
            }
        }
        return ans;
    }
};
