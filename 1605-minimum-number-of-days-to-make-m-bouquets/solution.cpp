class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        long long n = bd.size();
        long long t = (long long)m*k;
        if (t > n)
            return -1;
        int low = 0;
        int high = *max_element(bd.begin(), bd.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int flowers = 0;
            int bouquet = 0;
            for (int i = 0; i < n; i++) {
                if (bd[i] <= mid) {
                    flowers++;
                    if (flowers == k) {
                        bouquet++;
                        if (bouquet == m){
                            ans = mid;
                            high = mid - 1;
                        }
                        flowers = 0;
                    } 
                }
                else if (bd[i] > mid) {
                        flowers = 0;
                    }
            }
            if(bouquet < m) low = mid + 1;
            bouquet = 0;
            flowers = 0;
        }
        return ans;
    }
};
