class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 1;
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int ddays = 1;
            int load = 0;
            for(int i = 0; i < n; i++){
                if(load + weights[i] > mid){
                                        if(weights[i] > mid){
                                            ddays = days + 1;
                        low = mid + 1;
                        break;
                    }
                    ddays += 1;
                    load = weights[i];
                }
                else{
                    load += weights[i];
                }
            }
            if(ddays > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
