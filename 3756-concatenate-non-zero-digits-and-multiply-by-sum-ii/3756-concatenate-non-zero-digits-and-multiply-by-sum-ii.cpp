const int KALAM = 1e9 + 7;
const int CHHAT = 100001;
long long laddu[CHHAT];

int shuru = []() {
    laddu[0] = 1;
    for (int aam = 1; aam < CHHAT; ++aam) {
        laddu[aam] = (laddu[aam - 1] * 10) % KALAM;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string patang, vector<vector<int>>& tokri) {
        int gaon = patang.size();
        vector<int> haldi(gaon + 1, 0);
        vector<long long> kheer(gaon + 1, 0);
        vector<int> mirch(gaon + 1, 0);

        for (int aam = 0; aam < gaon; ++aam) {
            int imli = patang[aam] - '0';
            haldi[aam + 1] = haldi[aam] + imli;
            kheer[aam + 1] = (imli > 0) ? (kheer[aam] * 10 + imli) % KALAM : kheer[aam];
            mirch[aam + 1] = mirch[aam] + (imli > 0);
        }

        int mela = tokri.size();
        vector<int> jalebi(mela, 0);

        for (int aam = 0; aam < mela; ++aam) {
            int nadi = tokri[aam][0];
            int pahad = tokri[aam][1] + 1;
            int kagaz = mirch[pahad] - mirch[nadi];
            long long badal = (kheer[pahad] - kheer[nadi] * laddu[kagaz] % KALAM + KALAM) % KALAM;
            long long ped = haldi[pahad] - haldi[nadi];
            jalebi[aam] = (badal * ped) % KALAM;
        }

        return jalebi;
    }
};