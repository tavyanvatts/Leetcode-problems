class Solution {
public:
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    int mapST[256] = {0}; // 0 means "unmapped"; store t-char + 1 to avoid clashing with '\0'
    int mapTS[256] = {0};

    for (int i = 0; i < s.length(); i++) {
        unsigned char c1 = s[i], c2 = t[i];

        if (mapST[c1] == 0 && mapTS[c2] == 0) {
            mapST[c1] = c2 + 1;
            mapTS[c2] = c1 + 1;
        } else if (mapST[c1] != c2 + 1 || mapTS[c2] != c1 + 1) {
            return false;
        }
    }
    return true;
}
};
