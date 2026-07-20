class Solution {
public:
void comgen(vector<vector<int>> &ans, vector<int> temp, vector<int> &arr, int k, int n, int index){
    if(temp.size() == k){
        if(n == 0){
            ans.push_back(temp);
        }
        return;
    }
    else if(index == arr.size()) return;
    else if(n < 0) return;
    temp.push_back(arr[index]);
    n -= arr[index];
    comgen(ans, temp, arr, k, n, index + 1);
    temp.pop_back();
    n += arr[index];
    comgen(ans, temp, arr, k, n, index + 1);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        int index = 0;
        comgen(ans, temp, arr, k, n, index);
        return ans;
    }
};
