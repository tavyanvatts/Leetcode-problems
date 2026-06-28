class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            double sum = 0;
            for(int i = 0; i < n; i++){
                sum += ceil((double)nums[i]/(double)mid);
            }
            if(sum <= threshold){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
