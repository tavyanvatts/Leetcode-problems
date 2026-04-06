class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n = nums.size();
        int i=0;
        for(int j=0; j<n; j++){
           mpp[nums[j]]++;
           if(j-i <= k){
            if(mpp[nums[j]] > 1){
                return true;
            }
            continue;
           }
            mpp[nums[i]]--;
            if(mpp[nums[j]] > 1){
                return true;
            }
            i++;
        }
        return false;
    }
};
