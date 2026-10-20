class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // three case --> no negative numbers, even negative numbers, odd negative numbers
        // no and even are easy, problem is odd negative numbers, either we take product of prefix elements or we take product of suffix elements, if we encounter 0, we do not carry it forward, we take maximum of prefix product and suffix products, we find prefix products and suffix products in one go
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        int i = 0;
        while(i < n){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix = prefix*nums[i];
            suffix = suffix*nums[n - i - 1];
            maxi = max(maxi, prefix);
            maxi = max(maxi, suffix);
            i++;
        }
        return maxi;
    }
};
