class Solution {
public:
    bool parse(string &exp, int &ind) {
        char c = exp[ind];

        if (c == 't') { ind++; return true; }
        if (c == 'f') { ind++; return false; }

        if (c == '!') {
            ind += 2;                 // skip '!' and '('
            bool v = parse(exp, ind);
            ind++;                    // skip ')'
            return !v;
        }

        if (c == '&' || c == '|') {
            bool isAnd = (c == '&');
            ind += 2;                 // skip operator and '('
            bool res = isAnd;         // true for AND, false for OR
            while (exp[ind] != ')') {
                if (exp[ind] == ',') { ind++; continue; }
                bool v = parse(exp, ind);
                res = isAnd ? (res && v) : (res || v);
            }
            ind++;                    // skip ')'
            return res;
        }
        return false; // unreachable for valid input
    }

    bool parseBoolExpr(string expression) {
        int ind = 0;
        return parse(expression, ind);
    }
};
