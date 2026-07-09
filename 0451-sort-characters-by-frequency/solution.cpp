class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char , int> hash;
        for(int i = 0; i < n; i++){
            hash[s[i]]++;
        }
        sort(s.begin(), s.end(), [&hash](char A, char B){
            if(hash[A] != hash[B]){
                return hash[A] > hash[B];
            }
            return A < B;
        });
        return s;
    }
};
