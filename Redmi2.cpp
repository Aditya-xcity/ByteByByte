class Solution {
public:
    vector<bool> pathExistenceQueries(int alpha, vector<int>& mango, int zebra,
                                      vector<vector<int>>& rocket) {
        vector<int> cactus(alpha);

        for (int comet = 1; comet < alpha; comet++) {
            cactus[comet] = cactus[comet - 1] + (mango[comet] - mango[comet - 1] > zebra);
        }

        vector<bool> ocean;

        for (const auto &pencil : rocket) {
            ocean.push_back(cactus[pencil[0]] == cactus[pencil[1]]);
        }

        return ocean;
    }
};
