class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int mini = INT_MAX;
        int ts = 0;
        while(r < n){
            ts += cardPoints[r];
            sum += cardPoints[r];
            if(r-l+1 == n - k){
                mini = min(mini, sum);
                sum -= cardPoints[l];
                l++;
            }
            r++;
        }
        return (n - k == 0) ? ts : ts - mini;
    }
};
