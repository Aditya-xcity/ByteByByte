
class Solution {
public:
    bool checkValidString(string s) {
        int neecha = 0, upar = 0;

        for (auto& chacha : s) {
            neecha += ((chacha == '(') << 1) - 1;
            upar += ((chacha != ')') << 1) - 1;

            if (upar < 0) return 0;

            neecha = max(neecha, 0);
        }

        return neecha == 0;
    }
};
