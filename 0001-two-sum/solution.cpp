class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int index1 = -1;
        int index2 = -1;
        for (int j = 0; j < nums.size(); j++) {
            mpp[nums[j]]++;
            if (target - nums[j] == nums[j]) {
                if (mpp[target - nums[j]] > 1) {
                    index1 = j;
                    break;
                }
            } else {
                if (mpp[target - nums[j]] > 0) {
                    index1 = j;
                    break;
                }
            }
        }
        for (int i = 0; i < index1; i++) {
            if (nums[i] == target - nums[index1]) {
                index2 = i;
                break;
            }
        }
        return {index2, index1};
    }
};
