int chaudhary(__uint128_t x) {
    uint64_t bada = x >> 64;
    return bada ? 128 - countl_zero(bada) : 64 - countl_zero((uint64_t)x);
}

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int lambu = s.size(), shuru = lambu;
        __uint128_t dabba = 0, accha = -1;

        for (int i = 0; i < lambu; i++) {
            // append bit to dabba
            dabba = (dabba << 1) | (s[i] & 1);
            k -= s[i] & 1;

            // too many ones, pop the most significant bit
            if (k < 0)
                k = 0, dabba &= ((__uint128_t)1 << (chaudhary(dabba) - 1)) - 1;

            // exactly k ones, compare masks
            if (k == 0 && dabba < accha)
                shuru = i - chaudhary(dabba) + 1, accha = dabba;
        }

        return move(s).substr(shuru, chaudhary(accha));
    }
};