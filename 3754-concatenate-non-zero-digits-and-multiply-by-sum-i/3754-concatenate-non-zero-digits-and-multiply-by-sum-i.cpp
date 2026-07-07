class Solution {
public:
    long long sumAndMultiply(int sankhya) {
        long long badal = 0;
        long long yog = 0;
        string kagaz = to_string(sankhya);
        for (char akshar : kagaz) {
            int ank = akshar - '0';
            yog += ank;
            if (ank > 0) {
                badal = badal * 10 + ank;
            }
        }
        return badal * yog;
    }
};
