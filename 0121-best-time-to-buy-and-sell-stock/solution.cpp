class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = INT_MIN;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            if(prices[i] > buy){
                sell = prices[i];
                maxprofit = max(maxprofit, sell - buy);
            }
        }
        return maxprofit;
    }
};
