class Solution {
public:
    bool checkDivisibility(int n) {
        int yog = 0, guna = 1;

        for (int ank = n; ank > 0; ank /= 10) {
            const int shesh = ank % 10;
            yog += shesh;
            guna *= shesh;
        }

        return n % (yog + guna) == 0;
    }
};