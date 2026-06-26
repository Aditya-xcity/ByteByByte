class Solution {
public:
    long long countMajoritySubarrays(vector<int>& sankhya, int lakshya) {
        int lambai = sankhya.size();

        vector<int> purv(lambai * 2 + 1, 0);
        purv[lambai] = 1;

        int ginti = lambai;
        long long uttar = 0, yog = 0;

        for (int suchak = 0; suchak < lambai; ++suchak) {
            if (sankhya[suchak] == lakshya) {
                yog += purv[ginti];
                ++ginti;
                ++purv[ginti];
            } else {
                --ginti;
                yog -= purv[ginti];
                ++purv[ginti];
            }
            uttar += yog;
        }

        return uttar;
    }
};