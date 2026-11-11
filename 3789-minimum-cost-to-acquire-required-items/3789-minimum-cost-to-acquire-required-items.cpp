class Solution {
public:
    long long minimumCost(int paisa, int kharcha, int jugaad, int chahiye,
                          int aurChahiye) {
        long long totalBawaal = 0;

        if (paisa + kharcha <= jugaad) {
            totalBawaal = 1LL * paisa * chahiye + 1LL * kharcha * aurChahiye;
        } else {
            int kitnaLiya = min(chahiye, aurChahiye);
            totalBawaal = 1LL * kitnaLiya * jugaad;

            chahiye -= kitnaLiya;
            aurChahiye -= kitnaLiya;

            if (chahiye > 0) {
                totalBawaal += 1LL * chahiye * min(paisa, jugaad);
            }
            else if (aurChahiye > 0) {
                totalBawaal += 1LL * aurChahiye * min(kharcha, jugaad);
            }
        }

        return totalBawaal;
    }
};