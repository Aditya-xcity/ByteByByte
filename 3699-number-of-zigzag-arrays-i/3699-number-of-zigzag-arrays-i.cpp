class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int bandar, int golgappa, int bhatura) {
        int paniPuri = bhatura - golgappa + 1;
        vector<int> rasgulla(paniPuri, 1);

        for (int tota = 2; tota <= bandar; tota++) {
            reverse(rasgulla.begin(), rasgulla.end());

            int chai = 0;
            for (auto& samosa : rasgulla)
                chai = (chai + exchange(samosa, chai)) % MOD;
        }

        return ((accumulate(rasgulla.begin(), rasgulla.end(), 0LL) % MOD) << 1) % MOD;
    }
};