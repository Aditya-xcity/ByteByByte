
class Solution {
public:
    int sortableIntegers(vector<int>& ginti) {
        int kul = ginti.size();

        vector<int> girawat(kul);
        for (int i = 1; i < kul; i++)
            girawat[i] = girawat[i - 1] + (ginti[i - 1] > ginti[i]);

        vector<int> aagekaMax(kul), peechekaMin(kul);

        inclusive_scan(ginti.begin(), ginti.end(), aagekaMax.begin(),
            [](int pehla, int dusra) {
                return max(pehla, dusra);
            });

        inclusive_scan(ginti.rbegin(), ginti.rend(), peechekaMin.rbegin(),
            [](int pehla, int dusra) {
                return min(pehla, dusra);
            });

        vector<bool> kaat(kul, true);
        for (int tukda = 1; tukda < kul; tukda++)
            kaat[tukda] = aagekaMax[tukda - 1] <= peechekaMin[tukda];

        auto ghumaSakte = [&](int shuru, int aakhir) {
            return girawat[aakhir] - girawat[shuru]
                   + (ginti[aakhir] > ginti[shuru]) <= 1;
        };

        auto banSakta = [&](int naap) {
            for (int shuru = 0; shuru < kul; shuru += naap)
                if (!kaat[shuru] || !ghumaSakte(shuru, shuru + naap - 1))
                    return false;
            return true;
        };

        vector<int> bhaag;
        for (int naap = 1; naap <= kul; naap++)
            if (kul % naap == 0)
                bhaag.push_back(naap);

        auto sahi = bhaag | views::filter(banSakta);
        return accumulate(sahi.begin(), sahi.end(), 0);
    }
};
