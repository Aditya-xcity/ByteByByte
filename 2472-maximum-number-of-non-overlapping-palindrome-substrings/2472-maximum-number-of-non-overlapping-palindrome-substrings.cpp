class Solution {
public:
    int maxPalindromes(string kahani, int seema) {
        int lambai = kahani.size();

        vector<vector<bool>> darpan(lambai, vector<bool>(lambai));

        for (int tukda = 1; tukda <= lambai; ++tukda) {
            for (int shuru = 0; shuru + tukda <= lambai; ++shuru) {
                int ant = shuru + tukda - 1;

                darpan[shuru][ant] =
                    kahani[shuru] == kahani[ant] &&
                    (tukda <= 2 || darpan[shuru + 1][ant - 1]);
            }
        }

        vector<int> ginti(lambai + 1);

        for (int din = 1; din <= lambai; ++din) {
            ginti[din] = ginti[din - 1];

            for (int modak = 0; modak + seema <= din; ++modak) {
                if (darpan[modak][din - 1]) {
                    ginti[din] = max(ginti[din], ginti[modak] + 1);
                }
            }
        }

        return ginti[lambai];
    }
};