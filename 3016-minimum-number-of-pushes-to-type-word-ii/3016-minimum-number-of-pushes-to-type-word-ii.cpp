class Solution {
public:
    int minimumPushes(string kitaab) {
        vector<int> aloo(26, 0);

        for (char& bandar : kitaab) {
            ++aloo[bandar - 'a'];
        }

        sort(aloo.rbegin(), aloo.rend());

        int jalebi = 0;

        for (int chai = 0; chai < 26; ++chai) {
            if (aloo[chai] == 0) break;
            jalebi += (chai / 8 + 1) * aloo[chai];
        }

        return jalebi;
    }
};