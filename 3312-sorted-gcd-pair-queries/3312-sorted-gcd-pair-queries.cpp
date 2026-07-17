class Solution {
    using ll = long long;

public:
    vector<int> gcdValues(vector<int>& aam, vector<long long>& sawal) {
        int bada = ranges::max(aam);

        vector<int> tokri(bada + 1, 0);
        vector<ll> hisaab(bada + 1, 0);

        for (auto& dana : aam)
            tokri[dana]++;

        for (int ginti = bada; ginti > 0; ginti--) {
            ll jama = 0, bacha = 0;

            for (int kadam = ginti; kadam <= bada; kadam += ginti) {
                jama += tokri[kadam];
                bacha += hisaab[kadam];
            }

            hisaab[ginti] = jama * (jama - 1) / 2 - bacha;
        }

        partial_sum(hisaab.begin(), hisaab.end(), hisaab.begin());

        vector<int> jawab(sawal.size());

        for (int ginti = 0; ginti < sawal.size(); ginti++)
            jawab[ginti] =
                ranges::upper_bound(hisaab, sawal[ginti]) - hisaab.begin();

        return jawab;
    }
};