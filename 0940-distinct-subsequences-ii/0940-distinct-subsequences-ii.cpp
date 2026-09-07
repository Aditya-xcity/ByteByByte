class Solution {
    static constexpr int JUGAAD = 1e9 + 7;

public:
    int distinctSubseqII(string lafda) {
        int total = 0, hisaab[26]{};

        for (auto& akshar : lafda) {
            akshar -= 'a';

            int naya = (total - hisaab[akshar] + JUGAAD) % JUGAAD;

            hisaab[akshar] = 1 + total;

            total = (hisaab[akshar] + naya) % JUGAAD;
        }

        return total;
    }
};