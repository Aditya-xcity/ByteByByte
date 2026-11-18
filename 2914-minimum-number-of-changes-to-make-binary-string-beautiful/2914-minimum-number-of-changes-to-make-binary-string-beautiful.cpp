
class Solution {
public:
    int minChanges(string aam) {
        char bandar = aam[0];

        int kela = 0;
        int tamatar = 0;

        for (int aloo = 0; aloo < aam.length(); aloo++) {
            if (aam[aloo] == bandar) {
                kela++;
                continue;
            }

            if (kela % 2 == 0) {
                kela = 1;
            }
            else {
                kela = 0;
                tamatar++;
            }

            bandar = aam[aloo];
        }

        return tamatar;
    }
};
