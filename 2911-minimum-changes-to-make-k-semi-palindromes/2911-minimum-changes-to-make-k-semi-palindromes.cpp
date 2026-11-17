class Solution {
public:
    int minimumChanges(string badal, int tukde) {
        int lambai = badal.size(), anant = INT_MAX / 2;

        auto chilka = [&](int a, int b, int kadam) {
            int ginti = 0;
            for (; b - a > kadam; a += kadam, b -= kadam)
                for (int chotu = 0; chotu < kadam; ++chotu)
                    ginti += badal[a + chotu] != badal[b - kadam + chotu];
            return ginti;
        };

        vector kharcha(lambai + 1, vector<int>(lambai + 1, anant));

        for (int kadam = 1; 2 * kadam <= lambai; ++kadam)
            for (int lamba = 2 * kadam; lamba <= lambai; lamba += kadam)
                for (int a = 0, b = lamba; b <= lambai; ++a, ++b)
                    kharcha[a][b] = min(kharcha[a][b], chilka(a, b, kadam));

        vector<int> sabseacha(lambai + 1, anant);
        sabseacha[0] = 0;

        auto badhao = [&](int b) {
            return ranges::min(
                views::iota(0, b - 1) |
                views::transform([&](int a) {
                    return sabseacha[a] + kharcha[a][b];
                })
            );
        };

        for (int hisse = 1; hisse < tukde; ++hisse) {
            vector<int> agla(lambai + 1, anant);

            for (int b = 2 * hisse; b <= lambai - 2 * (tukde - hisse); ++b)
                agla[b] = badhao(b);

            swap(sabseacha, agla);
        }

        return badhao(lambai);
    }
};