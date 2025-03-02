class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int maxprod = INT_MIN;
        int backprod = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(prod == 0) prod = 1;
            if(backprod == 0) backprod = 1;
            prod = prod * nums[i];
            backprod = backprod * nums[nums.size() - i - 1];
            maxprod = max(maxprod , prod);
            maxprod = max(maxprod , backprod);
        }
        return maxprod;
    }
};
