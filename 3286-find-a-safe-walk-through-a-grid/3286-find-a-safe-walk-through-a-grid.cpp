class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& khet, int taakat) {
        int gaon = khet.size(), gali = khet[0].size();
        vector<vector<int>> hisaab(gaon, vector<int>(gali, -1));
        int raasta[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> dabba;

        dabba.emplace(khet[0][0], 0, 0);

        while (!dabba.empty()) {
            auto [kharcha, aadmi, makaan] = dabba.top();
            dabba.pop();

            if (hisaab[aadmi][makaan] >= 0)
                continue;

            hisaab[aadmi][makaan] = kharcha;

            for (int chai = 0; chai < 4; chai++) {
                int agla = aadmi + raasta[chai][0];
                int pichla = makaan + raasta[chai][1];

                if (agla < 0 || pichla < 0 || agla >= gaon || pichla >= gali ||
                    hisaab[agla][pichla] >= 0)
                    continue;

                dabba.emplace(kharcha + khet[agla][pichla], agla, pichla);
            }
        }

        return hisaab[gaon - 1][gali - 1] < taakat;
    }
};