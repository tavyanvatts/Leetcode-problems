class Solution {
public:
int function(vector<int>& nums, int k){
    int n = nums.size();
    int l = 0;
    int r = 0;
    int cnt = 0;
    unordered_map<int,int> hash;
    while(r < n){
        hash[nums[r]]++;
        while(hash.size() > k){
            hash[nums[l]]--;
            if(hash[nums[l]] == 0){
                hash.erase(nums[l]);
            }
            l++;
        }
        cnt += r - l + 1;
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k - 1);
    }
};
