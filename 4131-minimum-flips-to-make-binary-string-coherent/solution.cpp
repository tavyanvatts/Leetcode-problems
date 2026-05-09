class Solution {
public:
    int minFlips(string s) {
        string velnacirto = s;
    int n = velnacirto.size();

    int ones = count(velnacirto.begin(), velnacirto.end(), '1');
    int zeros = n - ones;

    
    int costA = ones;
    
    int costB = zeros;
    
    int costC = max(0, ones - 1);
    
    int costD = INT_MAX;
    if (n >= 2) {
        int ones_middle = ones - (velnacirto[0] == '1' ? 1 : 0) 
                                - (velnacirto[n-1] == '1' ? 1 : 0);
        costD = (velnacirto[0] == '0' ? 1 : 0) 
              + (velnacirto[n-1] == '0' ? 1 : 0) 
              + ones_middle;
    }

    return min({costA, costB, costC, costD});
    }
};
