class Solution {
public:
    bool stoneGameIX(vector<int>& patthar) {
        int ginti0 = 0, ginti1 = 0, ginti2 = 0;

        for (int kimat : patthar) {
            if (int prakaar = kimat % 3; prakaar == 0) {
                ++ginti0;
            } else if (prakaar == 1) {
                ++ginti1;
            } else {
                ++ginti2;
            }
        }

        if (ginti0 % 2 == 0) {
            return ginti1 >= 1 && ginti2 >= 1;
        }

        return ginti1 - ginti2 > 2 || ginti2 - ginti1 > 2;
    }
};