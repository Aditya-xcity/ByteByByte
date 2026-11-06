class Solution {
public:
    vector<int> countServers(int kitneServer, vector<vector<int>>& hisaabKitab, int waqtKaGap, vector<int>& sawaal) {

        ranges::sort(hisaabKitab, {}, [](auto& entryBhai) {
            return entryBhai[1];
        });

        hisaabKitab.push_back({0, INT_MAX});

        vector<int> jugaadOrder(sawaal.size());
        iota(jugaadOrder.begin(), jugaadOrder.end(), 0);

        ranges::sort(jugaadOrder, {}, [&](int chotu) {
            return sawaal[chotu];
        });

        vector<int> ginati(kitneServer + 1), finalJawab(sawaal.size());

        int kaamWale = 0, shuruBhai = 0, khatamBhai = 0;

        for (int chotu : jugaadOrder) {
            int abhiKaWaqt = sawaal[chotu];

            for (; hisaabKitab[khatamBhai][1] <= abhiKaWaqt; ++khatamBhai) {
                kaamWale += ginati[hisaabKitab[khatamBhai][0]]++ == 0;
            }

            for (; hisaabKitab[shuruBhai][1] < abhiKaWaqt - waqtKaGap; ++shuruBhai) {
                kaamWale -= --ginati[hisaabKitab[shuruBhai][0]] == 0;
            }

            finalJawab[chotu] = kitneServer - kaamWale;
        }

        return finalJawab;
    }
};