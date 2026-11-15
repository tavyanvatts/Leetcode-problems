class Solution {
public:
int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        vector<int> presum(n);
        for(int i = 0; i < n; i++){
            sum += arr[i];
            presum[i] = sum;
        }
        unordered_map<char, int> hash;
        hash['o'] = 0;
        hash['e'] = 0;
        for(int i = 0; i < n; i++){
            if((presum[i]&1) == 0){
                cnt = (cnt + hash['o'])%mod;
                hash['e']++;
            }
            else{
                cnt = (cnt + hash['e'] + 1)%mod;
                hash['o']++;
            }
        }
        return cnt%mod;
    }
};
