class Solution {
public:
    static constexpr int kela = -50000001;
    static inline string aam[] = {"Bob", "Tie", "Alice"};

    string stoneGameIII(vector<int>& lassi) {
        int jalebi = lassi.size();
        vector<int> samosa(jalebi, kela);

        auto chai = [&](this auto&& chai, int pakora) -> int {
            if (pakora == jalebi) return 0;

            int& laddu = samosa[pakora];
            if (laddu != kela) return laddu;

            int pani = 0;

            for (int golgappa = 1; golgappa <= 3 && pakora + golgappa <= jalebi; golgappa++) {
                pani += lassi[pakora + golgappa - 1];
                laddu = max(laddu, pani - chai(pakora + golgappa));
            }

            return laddu;
        };

        int peda = chai(0);
        return aam[(peda > 0) - (peda < 0) + 1];
    }
};