class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        long long high = 0;
        high = accumulate(monsters.begin(), monsters.end(), 0LL);
        vector<long long>diff(n+1,0);
        for(int i=0; i<boosts.size(); i++){
            diff[boosts[i][0]]+=boosts[i][2];
            diff[boosts[i][1]+1]-=boosts[i][2];
        }
        for(int i=1; i<n; i++){
            diff[i]+=diff[i-1];
        }
        long long low = 0;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long m = mid;
            bool e = true;
            for(int i = 0; i < n; i++){
                if(m + diff[i] >= monsters[i]) {m -= monsters[i]; m = max(m, 0LL);}
                else e = false;
            }
            if(e) {high = mid - 1; ans = mid;}
            else low = mid + 1;
        }
        return ans;
    }
};
