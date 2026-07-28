class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 1) return 1;
        unordered_map<int, int> hash;
        int i = 0;
        int type1 = fruits[0];
        int type2 = fruits[0];
        int ans = 1;
        for(int j = 0; j < fruits.size(); j++){
            hash[fruits[j]]++;
            if(fruits[j] == type1 || fruits[j] == type2){
                ans= max(ans, j - i + 1);
            }
            else{
                if(type1 == type2){
                    type2 = fruits[j];
                }
                else{
                    type2 = fruits[j];
                    while(hash[fruits[i]] != 0){
                        hash[fruits[i]]--;
                        if(hash[fruits[i]] == 0){
                            i++;
                            break;
                        }
                        i++;
                    }
                    type1 = fruits[i];
                }
                ans= max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
