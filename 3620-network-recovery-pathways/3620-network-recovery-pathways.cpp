class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& raste, vector<bool>& sakriya, long long seema) {
        int gaon = sakriya.size();

        vector<vector<pair<int,int>>> gali(gaon);
        vector<int> bhar(gaon, 0);

        for (auto &ped : raste) {
            gali[ped[0]].push_back({ped[1], ped[2]});
            bhar[ped[1]]++;
        }

        queue<int> dabba;
        for (int aam = 0; aam < gaon; aam++)
            if (bhar[aam] == 0)
                dabba.push(aam);

        vector<int> kram;
        while (!dabba.empty()) {
            int bandar = dabba.front();
            dabba.pop();
            kram.push_back(bandar);

            for (auto &[mor, bojh] : gali[bandar]) {
                if (--bhar[mor] == 0)
                    dabba.push(mor);
            }
        }

        auto jaanch = [&](int hadd) {
            const long long bada = (1LL << 60);

            vector<long long> hisaab(gaon, bada);
            hisaab[0] = 0;

            for (int sher : kram) {

                if (hisaab[sher] == bada)
                    continue;

                if (sher != 0 && sher != gaon - 1 && !sakriya[sher])
                    continue;

                for (auto &[hiran, taakat] : gali[sher]) {

                    if (taakat < hadd)
                        continue;

                    if (hiran != gaon - 1 && !sakriya[hiran])
                        continue;

                    if (hisaab[sher] + taakat < hisaab[hiran])
                        hisaab[hiran] = hisaab[sher] + taakat;
                }
            }

            return hisaab[gaon - 1] <= seema;
        };

        int chhota = 0, bada = 1000000000;
        int jawab = -1;

        while (chhota <= bada) {
            int beech = chhota + (bada - chhota) / 2;

            if (jaanch(beech)) {
                jawab = beech;
                chhota = beech + 1;
            } else {
                bada = beech - 1;
            }
        }

        return jawab;
    }
};