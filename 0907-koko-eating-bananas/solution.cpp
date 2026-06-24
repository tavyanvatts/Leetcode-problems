class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 0;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            double hrs = 0;
            for(int i = 0; i < n; i++){
                hrs += ceil((double)piles[i]/mid);
                if(hrs > h){
                    low = mid + 1;
                    break;
                }
            }
            if(hrs <= h){
                    ans = mid;
                    high = mid - 1;
                }
            hrs = 0;
        }
        return ans;
        }
};
