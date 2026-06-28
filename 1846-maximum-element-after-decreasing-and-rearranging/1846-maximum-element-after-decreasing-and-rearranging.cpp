class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& aam) {
        sort(aam.begin(), aam.end());

        int sher = 1;

        for (int bandar = 1; bandar < aam.size(); bandar++) {
            if (aam[bandar] >= sher + 1) {
                sher++;
            }
        }

        return sher;
    }
};