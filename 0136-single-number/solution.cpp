class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        map<int, int> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
            if(hash[nums[i]] == 1){
                sum += nums[i];
            }
            else{
                sum -= nums[i];
            }
        }
        return sum;
    }
};
