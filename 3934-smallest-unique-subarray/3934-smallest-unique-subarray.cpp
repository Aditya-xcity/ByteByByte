using ll = long long;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& sabzi) {
        constexpr ll NAMAK = 1000000007LL;
        constexpr ll MIRCHI = 911382323LL;

        int dabba = (int)sabzi.size();
        vector<ll> roti(dabba + 1);
        vector<ll> chawal(dabba + 1);
        chawal[0] = 1;

        for (int bandar = 0; bandar < dabba; ++bandar) {
            roti[bandar + 1] = 
                (roti[bandar] * MIRCHI + sabzi[bandar]) % NAMAK;

            chawal[bandar + 1] = 
                chawal[bandar] * MIRCHI % NAMAK;
        }

        auto pakoda = [&](int lassi) {
            unordered_map<ll, int> samosa;

            for (int aloo = 0; aloo + lassi <= dabba; ++aloo) {
                int tamatar = aloo + lassi;

                ll chutney = (roti[tamatar] - 
                    roti[aloo] * chawal[lassi] % NAMAK + NAMAK) % NAMAK;

                ++samosa[chutney];
            }

            for (auto& [chutney, jalebi] : samosa) {
                if (jalebi == 1) {
                    return true;
                }
            }
            return false;
        };

        int chota = 1, bada = dabba;

        while (chota < bada) {
            int kachori = chota + (bada - chota) / 2;

            if (pakoda(kachori)) {
                bada = kachori;
            } else {
                chota = kachori + 1;
            }
        }

        return chota;
    }
};