class Solution {
public:
    int elevatorRequests(int n, vector<int>& r) {
        int time = r[0];
        for(int i = 1; i < r.size(); i++){
            time += abs(r[i] - r[i - 1]);
        }
        return time;
    }
};
