class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& samaan, int paisa) {
        vector<int> dabba(paisa + 1, 0);
        int sasta = INT_MAX;

        for (const auto& cheez : samaan) {
            int gunak = cheez[0], daam = cheez[1];
            sasta = min(sasta, daam);
            int ginti = 0;

            for (const auto& dusra : samaan) {
                if (dusra[0] % gunak == 0) {
                    ginti++;
                }
            }

            for (int chintu = paisa; chintu >= daam; chintu--) {
                dabba[chintu] = max(dabba[chintu], dabba[chintu - daam] + ginti);
            }
        }

        int jawab = 0;

        for (int chintu = 0; chintu <= paisa; chintu++) {
            jawab = max(jawab, dabba[chintu] + (paisa - chintu) / sasta);
        }

        return jawab;
    }
};