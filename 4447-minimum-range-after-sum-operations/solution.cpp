class Solution {
public:
    int gr(vector<int> & v){
        return max({v[0],v[1], v[2]}) - min({v[0],v[1],v[2]});
    }
    int minRange(int a, int b, int c) {
        vector<int> i = {a, b, c};
        int ans = gr(i);
        vector<vector<int>> ns = {
            {b + c, b , c},
            {a, a+ c, c},
            {a, b, a + b}
        };
        for(auto& s : ns){
            ans = min(ans, gr(s));
        }
        return ans;
    }
};
