class Solution {
public:
    int maxDistance(string moves) {
        int x2 = 0;
        int y2 = 0;
        int n = moves.length();
        int cntu = 0, cntl = 0, cntd = 0, cntr = 0, cnts = 0;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'L') cntl++;
            else if(moves[i] == 'R') cntr++;
            else if(moves[i] == 'U') cntu++;
            else if(moves[i] == 'D') cntd++;
            else if(moves[i] == '_')cnts++;
        }
        for(int i = 0; i < n; i++){
            if(moves[i] == 'L') x2--;
            else if(moves[i] == 'R') x2++;
            else if(moves[i] == 'U') y2++;
            else if(moves[i] == 'D') y2--;
        }
        return abs(x2) + abs(y2) + cnts;
    }
};
