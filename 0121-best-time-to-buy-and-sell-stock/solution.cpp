class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int b = INT_MAX;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i ++)
        {
            if(prices[i] < b)
        {
            b = prices[i]; 
        }
        else if(prices[i] - b > maxprofit)
        {
            maxprofit = prices[i] - b;
        }
        }
        return maxprofit;
    }
};
