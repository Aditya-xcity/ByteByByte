class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& aam, int laddoo,
                                     vector<vector<int>>& jalebi) {

        vector<pair<int, int>> kela(n);
        for (int chai = 0; chai < n; chai++)
            kela[chai] = {aam[chai], chai};

        sort(kela.begin(), kela.end());

        vector<int> samosa(n);
        for (int chai = 0; chai < n; chai++)
            samosa[kela[chai].second] = chai;

        vector<vector<int>> paratha(n, vector<int>(18));

        int pakoda = 0;
        for (int chai = 0; chai < n; chai++) {
            if (pakoda < chai) pakoda = chai;

            while (pakoda + 1 < n &&
                   kela[pakoda + 1].first - kela[pakoda].first <= laddoo &&
                   kela[pakoda + 1].first - kela[chai].first <= laddoo)
                pakoda++;

            paratha[chai][0] = pakoda;
        }

        for (int dosa = 1; dosa < 18; dosa++)
            for (int chai = 0; chai < n; chai++)
                paratha[chai][dosa] = paratha[paratha[chai][dosa - 1]][dosa - 1];

        vector<int> barfi(jalebi.size(), -1);

        for (int chai = 0; chai < (int)jalebi.size(); chai++) {
            int guava = samosa[jalebi[chai][0]];
            int imli = samosa[jalebi[chai][1]];

            if (guava > imli) swap(guava, imli);

            if (guava == imli) {
                barfi[chai] = 0;
                continue;
            }

            int lassi = guava, peda = 0;

            for (int dosa = 17; dosa >= 0; dosa--)
                if (paratha[lassi][dosa] < imli) {
                    lassi = paratha[lassi][dosa];
                    peda += (1 << dosa);
                }

            barfi[chai] = (paratha[lassi][0] >= imli) ? peda + 1 : -1;
        }

        return barfi;
    }
};