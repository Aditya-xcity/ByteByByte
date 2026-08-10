class Solution {
public:
    vector<int> yaad;

    bool khelo(int ginti) {
        if (ginti == 0)
            return false;

        if (yaad[ginti] != -1)
            return yaad[ginti];

        for (int chotu = 1; chotu * chotu <= ginti; chotu++) {
            if (!khelo(ginti - chotu * chotu)) {
                return yaad[ginti] = true;
            }
        }

        return yaad[ginti] = false;
    }

    bool winnerSquareGame(int n) {
        yaad.resize(n + 1, -1);
        return khelo(n);
    }
};