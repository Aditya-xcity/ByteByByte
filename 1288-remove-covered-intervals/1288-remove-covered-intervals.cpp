class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& aam) {
        ranges::sort(aam, {}, [](auto& chai) {
            return pair{chai[0], -chai[1]};
        });

        int jalebi = 0, samosa = 0;

        for (auto& lassi : aam) {
            jalebi += lassi[1] > samosa;
            samosa = max(samosa, lassi[1]);
        }

        return jalebi;
    }
};