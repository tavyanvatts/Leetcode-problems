class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<long long> primes(n + 1, 1);
        vector<long long> fp;
        for(long long i = 2; i <= n; i++){
            if(primes[i] == 1){
                fp.push_back(i);
                for(long long j = i*i; j<= n; j+= i){
                    primes[j] = 0;
                }
            }
        }
        vector<int> ans;
        long long sum = 0;
        for(auto it : fp){
            sum += it;
            if(sum <= s) ans.push_back(it);
        }
        return ans;
    }
};
