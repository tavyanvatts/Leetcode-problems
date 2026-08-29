class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(((source[0] + source[1])&1) != ((target[0] + target[1])&1)) return -1;
        int t = abs(source[0] - target[0]);
        int k = abs(source[1] - target[1]);
        if((double)t/k == 1) return 1;
        else return 2;
    }
};
