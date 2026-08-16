class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& at) {
        vector<int> waiting(at.size());
        int pen = 0;
        int lm = *max_element(lights.begin(), lights.end());
        for(int i = 0; i < at.size(); i++){
            waiting[i] = at[i]%period;
            if(waiting[i] >= lm){
                pen = max(pen, period - waiting[i]);
            }
        }
        return pen;
    }
};
