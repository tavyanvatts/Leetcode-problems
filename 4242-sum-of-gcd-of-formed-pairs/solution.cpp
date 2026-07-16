class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd(n);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi) maxi = nums[i];
            prefixgcd[i] = gcd(maxi,nums[i]);
        }
        long long sum = 0;
        int i = 0;
        int j = n - 1;
        sort(prefixgcd.begin(), prefixgcd.end());
        while(i != j && i < j){
            sum += gcd(prefixgcd[i], prefixgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};
