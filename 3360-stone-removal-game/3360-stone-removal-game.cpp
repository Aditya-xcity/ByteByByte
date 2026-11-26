class Solution {
public:
    bool canAliceWin(int aam) {
        int samosa = 10, jalebi = 0;

        while (aam >= samosa) {
            aam -= samosa;
            samosa--;
            jalebi++;
        }

        return jalebi % 2 == 1;
    }
};