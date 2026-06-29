class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int fs, int fe) {
        int n = oi.size();
        vector<vector<int>> merged;
        sort(oi.begin(), oi.end());
        merged.push_back(oi[0]);
        for(int i = 1; i < n; i++){
        if(oi[i][0] <= merged[merged.size() - 1][1] || oi[i][0] == merged[merged.size() - 1][1] + 1){
                merged[merged.size() - 1][1] = max(merged[merged.size() - 1][1], oi[i][1]);
            }
            else{
                merged.push_back(oi[i]);
            }
        }
    
        
        for(int i = 0; i < merged.size(); i++){
            cout << "[" << merged[i][0] << "," << merged[i][1] << "]"; 
        }
        cout << endl;
        for(int i = 0; i < merged.size(); i++){
            if(merged[i][0] < fs && merged[i][1] < fs) continue;
            if(merged[i][0] > fe && merged[i][1] > fe) continue;
            if(merged[i][0] >= fs && merged[i][1] <= fe){
                merged.erase(merged.begin() + i);
                i--;
                continue;
            }
            if(merged[i][0] < fs && merged[i][1] > fe){
                merged.insert(merged.begin() + i + 1, {fe + 1, merged[i][1]});
                merged[i][1] = fs - 1;
                i++;
            }
            if(merged[i][1] >= fs && merged[i][0] < fs){
                merged[i][1] = fs -1;
            }
            if(merged[i][0] <= fe && merged[i][1] > fe){
                merged[i][0] = fe + 1;
            }
        }
        return merged;
    }
};
