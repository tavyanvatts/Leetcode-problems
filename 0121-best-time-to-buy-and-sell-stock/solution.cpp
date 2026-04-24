class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int n = prices.size();
        int maxprofit = INT_MIN;
        for(int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            maxprofit = max(maxprofit, prices[i] - mini);
        }
        return maxprofit;
    }
};
