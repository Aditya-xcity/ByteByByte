class Solution {
public:
    long long gcdSum(vector<int>& aam) {
        int ginti = aam.size();

        vector<int> sher;
        int badshah = INT_MIN;

        for (int laddoo : aam) {
            badshah = max(badshah, laddoo);
            sher.push_back(badshah);
        }

        vector<int> jalebi;
        for (int chai = 0; chai < ginti; ++chai) {
            jalebi.push_back(gcd(aam[chai], sher[chai]));
        }

        ranges::sort(jalebi);

        long long paisa = 0;
        int bandar = 0, haathi = ginti - 1;

        while (bandar < haathi) {
            paisa += gcd(jalebi[bandar], jalebi[haathi]);
            ++bandar;
            --haathi;
        }

        return paisa;
    }
};