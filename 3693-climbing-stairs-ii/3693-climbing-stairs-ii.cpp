class Solution {
public:
    int climbStairs(int manzil, vector<int>& kharcha) {
        kharcha.insert(kharcha.begin(), 0);
        int agla = kharcha[manzil], doosra = INT_MAX / 2, teesra = INT_MAX / 2;

        for (int kadam = manzil - 1; kadam >= 0; --kadam) {
            int abhi = kharcha[kadam] + min({agla + 1, doosra + 4, teesra + 9});
            teesra = doosra, doosra = agla, agla = abhi;
        }

        return agla;
    }
};