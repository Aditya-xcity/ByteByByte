class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& gaon) {
        int aakar = gaon.size();

        queue<pair<int, int>> tokri;

        for (int aam = 0; aam < aakar; aam++) {
            for (int imli = 0; imli < aakar; imli++) {
                if (gaon[aam][imli] == 1) {
                    tokri.push({aam, imli});
                    gaon[aam][imli] = 0;
                } else {
                    gaon[aam][imli] = -1;
                }
            }
        }

        while (!tokri.empty()) {
            int ginti = tokri.size();
            while (ginti-- > 0) {
                auto bandar = tokri.front();
                tokri.pop();

                for (auto& raasta : disha) {
                    int upar = bandar.first + raasta[0];
                    int neeche = bandar.second + raasta[1];
                    int doori = gaon[bandar.first][bandar.second];

                    if (theekHai(gaon, upar, neeche) && gaon[upar][neeche] == -1) {
                        gaon[upar][neeche] = doori + 1;
                        tokri.push({upar, neeche});
                    }
                }
            }
        }

        int shuru = 0;
        int antim = 0;
        int jawab = -1;

        for (int aam = 0; aam < aakar; aam++) {
            for (int imli = 0; imli < aakar; imli++) {
                antim = max(antim, gaon[aam][imli]);
            }
        }

        while (shuru <= antim) {
            int beech = shuru + (antim - shuru) / 2;

            if (milGaya(gaon, beech)) {
                jawab = beech;
                shuru = beech + 1;
            } else {
                antim = beech - 1;
            }
        }

        return jawab;
    }

private:
    vector<vector<int>> disha = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool theekHai(vector<vector<int>>& gaon, int aam, int imli) {
        int aakar = gaon.size();
        return aam >= 0 && imli >= 0 && aam < aakar && imli < aakar;
    }

    bool milGaya(vector<vector<int>>& gaon, int seema) {
        int aakar = gaon.size();

        if (gaon[0][0] < seema || gaon[aakar - 1][aakar - 1] < seema) {
            return false;
        }

        queue<pair<int, int>> tokri;
        vector<vector<bool>> dekha(aakar, vector<bool>(aakar, false));

        tokri.push({0, 0});
        dekha[0][0] = true;

        while (!tokri.empty()) {
            auto bandar = tokri.front();
            tokri.pop();

            if (bandar.first == aakar - 1 && bandar.second == aakar - 1) {
                return true;
            }

            for (auto& raasta : disha) {
                int upar = bandar.first + raasta[0];
                int neeche = bandar.second + raasta[1];

                if (theekHai(gaon, upar, neeche) &&
                    !dekha[upar][neeche] &&
                    gaon[upar][neeche] >= seema) {

                    dekha[upar][neeche] = true;
                    tokri.push({upar, neeche});
                }
            }
        }

        return false;
    }
};