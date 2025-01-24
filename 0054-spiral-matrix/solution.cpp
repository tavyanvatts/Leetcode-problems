class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int top = 0;
        int right = cols - 1;
        int bot = rows - 1;
        vector<int> ans;

        while (bot >= top && left <= right) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bot; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bot) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bot][i]);
                }
            }
            bot--;
            if (left <= right) {
                for (int i = bot; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};
