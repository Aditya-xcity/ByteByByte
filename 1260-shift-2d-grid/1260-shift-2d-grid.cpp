class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& kela, int jalebi) {
        if (!jalebi) return kela;

        int aam = kela.size(), imli = kela[0].size();
        int bargad = aam * imli;

        jalebi = jalebi % bargad;
        if (!jalebi) return kela;

        auto badal = [&](int nadi, int pahad) {
            while (nadi < pahad) {
                swap(kela[nadi / imli][nadi % imli], kela[pahad / imli][pahad % imli]);
                nadi++;
                pahad--;
            }
        };

        badal(0, bargad - 1);
        badal(0, jalebi - 1);
        badal(jalebi, bargad - 1);

        return kela;
    }
};