class Solution {
public:
    int largestOverlap(vector<vector<int>>& chitra, vector<vector<int>>& doosri) {
        int aakar = chitra.size();

        vector<pair<int,int>> pehli, dusri;

        for (int pankti = 0; pankti < aakar; ++pankti) {
            for (int stambh = 0; stambh < aakar; ++stambh) {
                if (chitra[pankti][stambh] == 1)
                    pehli.emplace_back(pankti, stambh);

                if (doosri[pankti][stambh] == 1)
                    dusri.emplace_back(pankti, stambh);
            }
        }

        vector<vector<int>> ginti(
            2 * aakar,
            vector<int>(2 * aakar, 0)
        );

        int sabseBadha = 0;

        for (auto& bindu1 : pehli) {
            for (auto& bindu2 : dusri) {
                int antarX = bindu2.first - bindu1.first + aakar;
                int antarY = bindu2.second - bindu1.second + aakar;

                sabseBadha = max(
                    sabseBadha,
                    ++ginti[antarX][antarY]
                );
            }
        }

        return sabseBadha;
    }
};