class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int score = 0;
            for(int j = 0; j < n-1; j++){
                if(s[j] == s[j+1])score++;
            }
            if(score == k)cnt++;
            int temp = s[0];
            s.erase(0,1);
            s += temp;
        }
        return cnt;
    }
};
