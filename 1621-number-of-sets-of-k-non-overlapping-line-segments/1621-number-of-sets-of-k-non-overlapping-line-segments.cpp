const int gunank = 1000000007;

class Solution {
public:
    int numberOfSets(int sankhya, int jode) {
        vector<int> hisaab(sankhya), yog(sankhya + 1);

        for (int pankti = 0; pankti < sankhya; pankti++) {
            hisaab[pankti] = 1;
            yog[pankti + 1] = (yog[pankti] + hisaab[pankti]) % gunank;
        }

        for (int chakra = 1; chakra <= jode; chakra++) {
            hisaab[0] = 0;

            for (int sthaan = 1; sthaan < sankhya; sthaan++) {
                hisaab[sthaan] = (hisaab[sthaan - 1] + yog[sthaan]) % gunank;
            }

            for (int sthaan = 0; sthaan < sankhya; sthaan++) {
                yog[sthaan + 1] = (yog[sthaan] + hisaab[sthaan]) % gunank;
            }
        }

        return hisaab[sankhya - 1];
    }
};