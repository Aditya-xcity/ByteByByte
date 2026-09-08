class Solution {
public:
    int countCommas(int n) {
        int ginti = 0;

        for (int sankhya = 1; sankhya <= n; sankhya++) {
            if (sankhya >= 1000) {
                ginti++;
            }
        }

        return ginti;
    }
};