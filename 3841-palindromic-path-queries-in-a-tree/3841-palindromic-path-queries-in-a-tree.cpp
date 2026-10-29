struct Tree {
    vector<int> baap, shuru, khatam, kram;
    vector<vector<int>> pehla;

    Tree(int n, vector<vector<int>>& kinare)
        : baap(n), shuru(n), khatam(n) {

        vector<int> ginti(n + 1), padosi(2 * n);

        for (auto& jodi : kinare)
            ginti[jodi[0] + 1]++, ginti[jodi[1] + 1]++;

        partial_sum(ginti.begin(), ginti.end(), ginti.begin());

        vector<int> jagah(ginti.begin(), ginti.end() - 1);

        for (auto& jodi : kinare)
            padosi[jagah[jodi[0]]++] = jodi[1],
            padosi[jagah[jodi[1]]++] = jodi[0];

        vector<int> dher = {0};

        while (!dher.empty()) {
            int banda = dher.back();
            dher.pop_back();

            if (banda < 0) {
                khatam[~banda] = kram.size();
                continue;
            }

            shuru[banda] = kram.size();
            kram.push_back(banda);
            dher.push_back(~banda);

            for (int i = ginti[banda]; i < ginti[banda + 1]; i++)
                if (int dost = padosi[i]; dost != baap[banda]) {
                    baap[dost] = banda;
                    dher.push_back(dost);
                }
        }

        pehla.emplace_back(n);

        for (int i = 0; i < n; i++)
            pehla[0][i] = shuru[baap[kram[i]]];

        for (int gehra = 1; 1 << gehra <= n; gehra++) {
            pehla.emplace_back(n - (1 << gehra) + 1);

            for (int i = 0; i + (1 << gehra) <= n; i++)
                pehla[gehra][i] = min(
                    pehla[gehra - 1][i],
                    pehla[gehra - 1][i + (1 << (gehra - 1))]
                );
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;

        auto [baaya, daaya] = minmax(shuru[a], shuru[b]);

        int gehra = bit_width(unsigned(daaya - baaya)) - 1;

        return kram[min(
            pehla[gehra][baaya + 1],
            pehla[gehra][daaya - (1 << gehra) + 1]
        )];
    }
};

struct RootPaths {
    Tree& ped;
    vector<int> pehle, hisaab;

    RootPaths(Tree& ped, vector<int>& akshar)
        : ped(ped), pehle(akshar), hisaab(akshar.size() + 1) {

        for (int banda : ped.kram)
            if (banda != ped.baap[banda])
                pehle[banda] ^= pehle[ped.baap[banda]];
    }

    void flip(int banda, int badlaav) {
        for (int jagah : {ped.shuru[banda] + 1, ped.khatam[banda] + 1})
            for (; jagah < (int)hisaab.size(); jagah += jagah & -jagah)
                hisaab[jagah] ^= badlaav;
    }

    int operator[](int banda) {
        int nakaab = pehle[banda];

        for (int jagah = ped.shuru[banda] + 1; jagah > 0; jagah -= jagah & -jagah)
            nakaab ^= hisaab[jagah];

        return nakaab;
    }
};

class Solution {
public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        Tree ped(n, edges);

        vector<int> akshar(n);

        for (int banda = 0; banda < n; banda++)
            akshar[banda] = 1 << (s[banda] - 'a');

        RootPaths raasta(ped, akshar);

        vector<bool> jawab;

        for (auto& sawaal : queries) {
            if (sawaal[0] == 'u') {
                int banda = number(sawaal, 7);
                int naya = 1 << (sawaal.back() - 'a');

                raasta.flip(banda, akshar[banda] ^ naya);
                akshar[banda] = naya;
            } else {
                int pehlaBanda = number(sawaal, 6);
                int doosraBanda = number(sawaal, sawaal.rfind(' ') + 1);

                int nakaab = raasta[pehlaBanda]
                           ^ raasta[doosraBanda]
                           ^ akshar[ped.lca(pehlaBanda, doosraBanda)];

                jawab.push_back(popcount(unsigned(nakaab)) <= 1);
            }
        }

        return jawab;
    }

private:
    static int number(const string& sawaal, int jagah) {
        int ank = 0;

        for (; jagah < (int)sawaal.size() && isdigit(sawaal[jagah]); jagah++)
            ank = ank * 10 + (sawaal[jagah] - '0');

        return ank;
    }
};