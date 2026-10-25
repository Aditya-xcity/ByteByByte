class Solution {
public:
    int closedIsland(vector<vector<int>>& naksha) {
        int pankti = naksha.size();
        int stambh = naksha[0].size();
        vector<vector<bool>> dekha(pankti, vector<bool>(stambh));
        int ginti = 0;

        for (int aam = 0; aam < pankti; aam++) {
            for (int imli = 0; imli < stambh; imli++) {
                if (naksha[aam][imli] == 0 && !dekha[aam][imli] &&
                    bfs(aam, imli, pankti, stambh, naksha, dekha)) {
                    ginti++;
                }
            }
        }
        return ginti;
    }

    bool bfs(int sher, int mor, int pankti, int stambh,
             vector<vector<int>>& naksha,
             vector<vector<bool>>& dekha) {
        queue<pair<int, int>> dibba;
        dibba.push({sher, mor});
        dekha[sher][mor] = true;
        bool band = true;

        vector<int> dishaX{0, 1, 0, -1};
        vector<int> dishaY{-1, 0, 1, 0};

        while (!dibba.empty()) {
            sher = dibba.front().first;
            mor = dibba.front().second;
            dibba.pop();

            for (int tota = 0; tota < 4; tota++) {
                int haathi = sher + dishaX[tota];
                int bandar = mor + dishaY[tota];

                if (haathi < 0 || haathi >= pankti ||
                    bandar < 0 || bandar >= stambh) {
                    band = false;
                } else if (naksha[haathi][bandar] == 0 &&
                           !dekha[haathi][bandar]) {
                    dibba.push({haathi, bandar});
                    dekha[haathi][bandar] = true;
                }
            }
        }

        return band;
    }
};