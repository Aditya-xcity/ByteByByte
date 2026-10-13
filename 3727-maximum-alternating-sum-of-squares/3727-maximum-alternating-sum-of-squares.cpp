class Solution {
public:
    long long maxAlternatingSum(vector<int>& dabbe) {
        vector<long long> varg;
        for (int ginti : dabbe) varg.push_back(1LL * ginti * ginti);

        int aadha = varg.size() / 2;
        nth_element(varg.begin(), varg.begin() + aadha, varg.end());

        long long kul = accumulate(varg.begin(), varg.end(), 0LL);
        long long chhota = accumulate(varg.begin(), varg.begin() + aadha, 0LL);

        return kul - 2 * chhota;
    }
};