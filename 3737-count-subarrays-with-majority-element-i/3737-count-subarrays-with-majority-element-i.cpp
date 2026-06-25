class Solution {
public:
    int countMajoritySubarrays(vector<int>& aam, int sher) {
        int lambai = aam.size();
        int jawab = 0;

        for (int shuru = 0; shuru < lambai; ++shuru) {
            int ginti = 0;

            for (int ant = shuru; ant < lambai; ++ant) {
                ginti += (aam[ant] == sher ? 1 : -1);

                if (ginti > 0) {
                    ++jawab;
                }
            }
        }

        return jawab;
    }
};