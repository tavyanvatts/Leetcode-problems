class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        int ans = 0;
        vector<bool> k(n, false);
        for (int i = 0; i < n; i++) {
            if (lights[i] != 0) {
                fill(k.begin() + (max(0, i - lights[i])),
                     k.begin() + (min(n - 1, i + lights[i])) + 1, true);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(k[i] == false){
                cnt++;
                if(cnt == 3){
                    ans++;
                    cnt = 0;
                }
            }
            if(k[i] == true && cnt != 0){
                ans++;
                cnt = 0;
            }
        }
        if(cnt != 0) ans++;
        return ans;
    }
};
