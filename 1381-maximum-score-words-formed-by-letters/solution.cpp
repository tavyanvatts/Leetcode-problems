class Solution {
public:

int function(vector<string>& words, vector<int>& score, unordered_map<char, int> &hash, int ind){

    if(ind == words.size()) return 0;
    unordered_map<char, int> currhash = hash;
    int sc1 = 0, sc2 = 0;
    bool k = false;
    for(int i = 0; i < words[ind].length(); i++){
        if(currhash[words[ind][i]] > 0){
            sc1 += score[words[ind][i] - 97];
            currhash[words[ind][i]]--;
        }
        else{
            k = true;
            break;
        }
    }
    sc1 = (k) ? 0 + function(words, score, hash, ind + 1) : sc1 + function(words, score, currhash, ind + 1); 
    sc2 = 0 + function(words, score, hash, ind + 1);

    return max(sc1, sc2);
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> hash;
        for(int i = 0; i < letters.size(); i++){
            hash[letters[i]]++;
        }
        return function(words, score, hash, 0);
    }
};
