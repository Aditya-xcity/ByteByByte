class SegmentTree {
private:
    int aakar;
    vector<int> ank;
    vector<int> ped;

    void banao(int jad, int baaya, int daaya) {
        if (baaya == daaya) {
            ped[jad] = ank[baaya];
            return;
        }

        int beech = (baaya + daaya) >> 1;
        banao(jad << 1, baaya, beech);
        banao(jad << 1 | 1, beech + 1, daaya);
        ped[jad] = max(ped[jad << 1], ped[jad << 1 | 1]);
    }

    int khojo(int jad, int baaya, int daaya, int shuru, int ant) {
        if (shuru <= baaya && daaya <= ant) {
            return ped[jad];
        }

        int beech = (baaya + daaya) >> 1;
        int uttar = 0;

        if (shuru <= beech) {
            uttar = max(uttar, khojo(jad << 1, baaya, beech, shuru, ant));
        }
        if (ant > beech) {
            uttar = max(uttar, khojo(jad << 1 | 1, beech + 1, daaya, shuru, ant));
        }

        return uttar;
    }

public:
    SegmentTree(const vector<int>& ank) : ank(ank) {
        aakar = ank.size();
        ped.resize(aakar << 2, 0);
        banao(1, 0, aakar - 1);
    }

    int query(int shuru, int ant) {
        if (shuru > ant) {
            return 0;
        }

        return khojo(1, 0, aakar - 1, shuru, ant);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string dhaaga,
                                            vector<vector<int>>& prashn) {
        int lambai = dhaaga.length();
        int ekGinti = count(dhaaga.begin(), dhaaga.end(), '1');

        vector<int> shunyaTukde;
        vector<int> baayaKinara;
        vector<int> daayaKinara;

        int soochak = 0;
        while (soochak < lambai) {
            int aarambh = soochak;
            while (soochak < lambai && dhaaga[soochak] == dhaaga[aarambh]) {
                soochak++;
            }

            if (dhaaga[aarambh] == '0') {
                shunyaTukde.push_back(soochak - aarambh);
                baayaKinara.push_back(aarambh);
                daayaKinara.push_back(soochak - 1);
            }
        }

        int tukde = shunyaTukde.size();
        if (tukde < 2) {
            return vector<int>(prashn.size(), ekGinti);
        }

        vector<int> yog(tukde - 1);
        for (int kram = 0; kram < tukde - 1; kram++) {
            yog[kram] = shunyaTukde[kram] + shunyaTukde[kram + 1];
        }

        SegmentTree vriksh(yog);
        vector<int> uttar;

        for (const auto& sawaal : prashn) {
            int baaya = sawaal[0];
            int daaya = sawaal[1];

            int pehla = lower_bound(daayaKinara.begin(), daayaKinara.end(), baaya)
                        - daayaKinara.begin();
            int aakhri = upper_bound(baayaKinara.begin(), baayaKinara.end(), daaya)
                         - baayaKinara.begin() - 1;

            if (pehla > tukde - 1 || aakhri < 0 || pehla >= aakhri) {
                uttar.push_back(ekGinti);
                continue;
            }

            int pehliLambai =
                daayaKinara[pehla] - max(baayaKinara[pehla], baaya) + 1;

            int aakhriLambai =
                min(daayaKinara[aakhri], daaya) - baayaKinara[aakhri] + 1;

            if (pehla + 1 == aakhri) {
                int sabseAccha = pehliLambai + aakhriLambai;
                uttar.push_back(ekGinti + sabseAccha);
                continue;
            }

            int pehlaMoolya = pehliLambai + shunyaTukde[pehla + 1];
            int doosraMoolya = shunyaTukde[aakhri - 1] + aakhriLambai;
            int teesraMoolya = vriksh.query(pehla + 1, aakhri - 2);

            int sabseAccha = max({pehlaMoolya, doosraMoolya, teesraMoolya});
            uttar.push_back(ekGinti + sabseAccha);
        }

        return uttar;
    }
};