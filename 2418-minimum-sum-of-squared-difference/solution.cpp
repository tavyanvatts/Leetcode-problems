class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxi = INT_MIN;
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, nums1[i]);
        }
        int low = 0, high = maxi;
        int res = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int k = k1 + k2;
            long long cost = 0;
            for(int i = 0; i < n; i++){
                cost += max(0, nums1[i] - mid);
            }
            if(cost <= k){
                high = mid - 1;
                res = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int k = k1 + k2;
        for(int i = 0; i < n; i++){
            if(nums1[i] > res){
                k -= (nums1[i] - res);
                nums1[i] = res;
            }
        }
            sort(nums1.rbegin(), nums1.rend());
            for(int i = 0; i < n; i++){
                if(k > 0){if(nums1[i] > 0){
                    nums1[i]--;
                    k--;
                }}
                else break;
            }
        long long ans = 0;
        for(auto num : nums1){
            ans += 1LL*num*num;
        }
        return ans;
    }
};
