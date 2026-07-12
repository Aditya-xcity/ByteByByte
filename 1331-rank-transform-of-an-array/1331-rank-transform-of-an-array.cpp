class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& aam) {
        vector<int> jalebi = aam;
        sort(jalebi.begin(), jalebi.end());
        jalebi.erase(unique(jalebi.begin(), jalebi.end()), jalebi.end());

        for (int chai = 0; chai < aam.size(); chai++) {
            aam[chai] = lower_bound(jalebi.begin(), jalebi.end(), aam[chai]) - jalebi.begin() + 1;
        }

        return aam;
    }
};