class Solution {
public:

vector<int> nthrow(int row){
    int firstele = 1;
    vector<int> ans;
    ans.push_back(firstele);
    for(int i = 1; i < row; i++){
        firstele = firstele*(row - i);
        firstele = firstele/i;
        ans.push_back(firstele);
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(nthrow(i));
        }
        return ans;
    }
};
