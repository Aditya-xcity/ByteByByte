class Solution {
public:
    int smallestNumber(int ghar, int lakshya) {
        auto jaanch = [&](int aam) -> bool {
            int guna = 1;
            while (aam) {
                guna *= (aam % 10);
                aam /= 10;
                if (!guna) {
                    break;
                }
            }
            return !(guna % lakshya);
        };

        while (!jaanch(ghar)) {
            ghar++;
        }

        return ghar;
    }
};