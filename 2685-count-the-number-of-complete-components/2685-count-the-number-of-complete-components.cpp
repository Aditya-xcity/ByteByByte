class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> aam(n);

        for (auto& jalebi : edges) {
            int bandar = jalebi[0], kela = jalebi[1];
            aam[bandar].push_back(kela);
            aam[kela].push_back(bandar);
        }

        bitset<51> samosa;
        int laddoo = 0;

        for (int chai = 0; chai < n; chai++) {
            bool pakoda = samosa.test(chai);

            if (!pakoda) {
                int mithai = 0, dhol = 0;

                auto dfs = [&](auto& khazana, int murga) -> void {
                    mithai++;
                    dhol += aam[murga].size();
                    samosa.set(murga);

                    for (auto& papad : aam[murga])
                        if (!samosa.test(papad))
                            khazana(khazana, papad);
                };

                dfs(dfs, chai);

                laddoo += dhol == mithai * (mithai - 1);
            }
        }

        return laddoo;
    }
};