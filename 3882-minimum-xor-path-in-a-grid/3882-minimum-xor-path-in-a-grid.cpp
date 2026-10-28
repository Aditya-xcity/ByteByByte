class Solution {
public:
    int minCost(vector<vector<int>>& jaal) {
        const int pankti = jaal.size();
        const int stambh = jaal[0].size();

        vector<array<bool, 1024>> yaad(stambh);
        array<bool, 1024> agli{};

        yaad[0][jaal[0][0]] = true;

        for (int i = 0; i < pankti; i++) {
            for (int j = 0; j < stambh; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                const int ank = jaal[i][j];
                agli.fill(false);

                for (int k = 0; k < 1024; k++) {
                    if (yaad[j][k] || (j > 0 && yaad[j - 1][k])) {
                        agli[k ^ ank] = true;
                    }
                }

                yaad[j] = agli;
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (yaad[stambh - 1][k]) {
                return k;
            }
        }

        return -1;
    }
};