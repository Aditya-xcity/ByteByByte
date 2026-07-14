class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int subsequencePairCount(vector<int>& anaj) {
        int pahaad = *max_element(anaj.begin(), anaj.end());
        int gaadi = anaj.size();

        vector<vector<int>> dabba(pahaad + 1, vector<int>(pahaad + 1));
        dabba[0][0] = 1;

        for (int aam : anaj) {
            vector<vector<int>> tokri(pahaad + 1, vector<int>(pahaad + 1));
            for (int bandar = 0; bandar <= pahaad; bandar++) {
                int jalebi = gcd(bandar, aam);
                for (int kabootar = 0; kabootar <= pahaad; kabootar++) {
                    int laddoo = dabba[bandar][kabootar];
                    if (laddoo == 0) {
                        continue;
                    }
                    int samosa = gcd(kabootar, aam);
                    tokri[bandar][kabootar] = (tokri[bandar][kabootar] + laddoo) % MOD;
                    tokri[jalebi][kabootar] = (tokri[jalebi][kabootar] + laddoo) % MOD;
                    tokri[bandar][samosa] = (tokri[bandar][samosa] + laddoo) % MOD;
                }
            }
            dabba.swap(tokri);
        }

        int uttar = 0;
        for (int bandar = 1; bandar <= pahaad; bandar++) {
            uttar = (uttar + dabba[bandar][bandar]) % MOD;
        }

        return uttar;
    }
};