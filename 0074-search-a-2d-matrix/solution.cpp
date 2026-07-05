class Solution {
public:
    int searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int low = 0;
        int high = n - 1;
        int row;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] == target || matrix[mid][matrix[mid].size() - 1] == target) return true;
            if(matrix[mid][0] > target){
                high = mid - 1;
            }
            else if(matrix[mid][matrix[mid].size() - 1] < target){
                low = mid + 1;
            }
            else if(matrix[mid][0] < target && matrix[mid][matrix[mid].size() - 1] > target){
                row = mid;
                break;
            }
        }
        low = 0;
        high = matrix[row].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid] > target){
                high = mid - 1;
            }
            else if(matrix[row][mid] < target){
                low = mid + 1;
            }
            if(matrix[row][mid] == target) return true;
        }
        return false;
    }
};
