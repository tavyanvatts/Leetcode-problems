class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long> presum;
        long long sum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            presum.push_back(sum);
        }
        for(int i = 0; i < presum.size(); i++){
            for(int j = i; j < presum.size(); j++){
                long long subsum = 0;
                if(i - 1 < 0){
                    subsum = presum[j];
                }
                else{
                    subsum = presum[j] - presum[i - 1];
                }
                int lst = subsum%10;
                int fst = -1;
                while(subsum > 0){
                    fst = subsum;
                    subsum = subsum/10;
                }
                if(lst == x && fst == x) cnt++;
            }
        }
        return cnt;
    }
};
