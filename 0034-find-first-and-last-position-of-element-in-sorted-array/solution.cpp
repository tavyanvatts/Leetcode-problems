class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1, last = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                high = mid - 1;
                first = mid;
            }
            cout << first << " ";
        }
        cout << endl;
        low = 0;
        high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
                last = mid;
            }
            cout << last << " ";
        }
        cout << endl;
        return {first, last};
    }
};
