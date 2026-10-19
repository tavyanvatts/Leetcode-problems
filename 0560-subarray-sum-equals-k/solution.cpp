class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        vector<int> pre(n);
        for(int i = 0; i < n; i++){
            sum += nums[i];
            pre[i] = sum;
        }
        unordered_map<int,int> hash;
        hash[0]++;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            sum = pre[i];
            int rem = sum - k;
            if(hash.find(rem) != hash.end()){
                cnt += hash[rem];
            }
            hash[sum]++;
        }
        return cnt;
    }
};
