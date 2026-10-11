class Solution {
public:
    int sumOfSquares(vector<int>& sankhya) {
        int lambai = sankhya.size();
        int yog = 0;

        for (int ganak = 1; ganak * ganak <= lambai; ++ganak) {
            if (lambai % ganak == 0) {
                yog += sankhya[ganak - 1] * sankhya[ganak - 1];

                if (ganak * ganak != lambai) {
                    yog += sankhya[lambai / ganak - 1] *
                           sankhya[lambai / ganak - 1];
                }
            }
        }

        return yog;
    }
};