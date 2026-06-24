class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix guna(const Matrix& aam, const Matrix& imli) {
        int aakar = aam.size();
        int chaudai = imli[0].size();

        Matrix parinaam(aakar, vector<long long>(chaudai, 0));

        for (int laddoo = 0; laddoo < aakar; laddoo++) {
            for (int jalebi = 0; jalebi < aam[0].size(); jalebi++) {
                long long rasgulla = aam[laddoo][jalebi];

                if (rasgulla == 0) {
                    continue;
                }

                for (int samosa = 0; samosa < chaudai; samosa++) {
                    parinaam[laddoo][samosa] =
                        (parinaam[laddoo][samosa] +
                         rasgulla * imli[jalebi][samosa]) % MOD;
                }
            }
        }

        return parinaam;
    }

    Matrix shakti(Matrix ped, long long taakat, Matrix phal) {
        while (taakat > 0) {
            if (taakat & 1) {
                phal = guna(phal, ped);
            }

            ped = guna(ped, ped);
            taakat >>= 1;
        }

        return phal;
    }

public:
    int zigZagArrays(int ghar, int chhota, int bada) {
        int range = bada - chhota + 1;

        if (ghar == 1) {
            return range;
        }

        int doGuna = 2 * range;

        Matrix chakravyuh(doGuna, vector<long long>(doGuna, 0));

        for (int kela = 0; kela < range; kela++) {
            for (int aam = 0; aam < kela; aam++) {
                chakravyuh[kela][aam + range] = 1;
            }

            for (int aam = kela + 1; aam < range; aam++) {
                chakravyuh[kela + range][aam] = 1;
            }
        }

        Matrix hisaab(1, vector<long long>(doGuna, 1));

        hisaab = shakti(std::move(chakravyuh), ghar - 1, std::move(hisaab));

        long long jawaab = 0;

        for (int chai = 0; chai < doGuna; chai++) {
            jawaab = (jawaab + hisaab[0][chai]) % MOD;
        }

        return jawaab;
    }
};