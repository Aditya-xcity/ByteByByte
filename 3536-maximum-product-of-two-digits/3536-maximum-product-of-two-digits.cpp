class Solution {
public:
    int maxProduct(int sankhya) {
        int aam = 0, kela = 0;
        while (sankhya > 0) {
            int laddu = sankhya % 10;
            if (laddu > aam) {
                kela = aam;
                aam = laddu;
            } else if (laddu > kela) {
                kela = laddu;
            }
            sankhya /= 10;
        }
        return aam * kela;
    }
};