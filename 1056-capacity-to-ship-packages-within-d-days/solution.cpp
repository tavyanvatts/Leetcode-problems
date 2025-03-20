class Solution {
public:
    bool isittherightcap(vector<int>& weights, int days, int cap) {
        int i = 0;
        int t = cap;
        while (i != weights.size() && days != 0) {
            if (t >= weights[i]) {
                t = t - weights[i];
                i++;
            } else {
                days--;
                t = cap;
            }
        }
        if (days == 0) {
            return false;
        } else {
            return true;
        }
    }
    int sumi(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum = sum + weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = sumi(weights);
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool ok = isittherightcap(weights, days, mid);
            if (ok == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
