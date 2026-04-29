class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        for(int i = 0; i < nums.size(); i++){
            hash.insert(nums[i]);
        }
        int len = 0;
        int cnt;
        for(auto it : hash){
            if(hash.find(it - 1) == hash.end()){
                cnt = 1;
            }
            else if(hash.find(it - 1) != hash.end()){
                cnt++;
            }
            len = max(len, cnt);
        }
        return len;
    }
};
