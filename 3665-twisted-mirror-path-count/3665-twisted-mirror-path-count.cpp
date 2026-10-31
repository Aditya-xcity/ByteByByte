class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int jugaad = 1e9 + 7;
        vector<int> neeche(grid[0].size());
        neeche[0] = 1;

        for (auto& gali : grid) {
            int daaye = 0;

            for (int chintu = 0; chintu < gali.size(); chintu++) {
                if (gali[chintu]) {
                    swap(daaye, neeche[chintu]);
                } else {
                    daaye = neeche[chintu] =
                        (daaye + neeche[chintu]) % jugaad;
                }
            }
        }

        return neeche.back();
    }
};