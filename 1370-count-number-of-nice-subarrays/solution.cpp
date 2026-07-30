class Solution {
public:
int function(vector<int>& nums, int k){
    int cnt = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        while(r < nums.size()){
            if(nums[r]%2 == 1){
                sum++;
            }
            while(sum > k){
                if(nums[l]%2 == 1){
                    sum--;
                }
                l++;
            }
            if(sum <= k){cnt += r - l + 1;}
            r++;
        }
        return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k - 1);
    }
};
