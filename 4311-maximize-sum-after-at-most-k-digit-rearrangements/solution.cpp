class Solution {
public:
    long long maxar(int num){
        int count[10] = {0};
        while(num > 0){
            count[num%10]++;
            num /= 10;
        }
        long long maxi = 0;
        for(int i = 9; i >= 0; i--){
            while(count[i] > 0){
                maxi = (maxi*10) + i;
                count[i]--;
            }
        }
        return maxi;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<long long> diff(n);
        for(int i = 0; i < n; i++){
            sum += nums[i];
            long long r = maxar(nums[i]);
            diff[i] = (r - nums[i]);
        }
        sort(diff.rbegin(), diff.rend());
        for(auto it : diff){
            if(k > 0){
                sum += it;
                    k--;
            }
            else break;
        }
        return sum;
    }
};
