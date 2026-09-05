class Solution {
public:
    int firstStableIndex(vector<int>& sankhya, int seema) {
        int lambai = sankhya.size();

        vector<int> chhotiSankhya(lambai);

        chhotiSankhya[lambai - 1] = sankhya[lambai - 1];

        for (int i = lambai - 2; i >= 0; --i) {
            chhotiSankhya[i] = min(chhotiSankhya[i + 1], sankhya[i]);
        }

        int badiSankhya = 0;

        for (int i = 0; i < lambai; ++i) {
            badiSankhya = max(badiSankhya, sankhya[i]);

            if (badiSankhya - chhotiSankhya[i] <= seema) {
                return i;
            }
        }

        return -1;
    }
};