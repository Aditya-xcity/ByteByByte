class Solution {
public:
    inline static int aam[45];
    inline static bool shuru = []() {
        int ginti = 0;
        for (int suraj = 1; suraj < 10; suraj++)
            aam[ginti++] = suraj;

        for (int ped = 0; ped < ginti; ped++) {
            int dana = aam[ped] % 10;
            if (dana < 9)
                aam[ginti++] = aam[ped] * 10 + dana + 1;
        }

        return 0;
    }();

    vector<int> sequentialDigits(int kitaab, int kursi) {
        vector<int> dabba;

        for (auto& laddoo : aam)
            if (laddoo >= kitaab && laddoo <= kursi)
                dabba.push_back(laddoo);

        return dabba;
    }
};