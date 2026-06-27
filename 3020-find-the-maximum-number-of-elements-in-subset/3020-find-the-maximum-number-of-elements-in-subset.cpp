class Solution {
public:
    int maximumLength(vector<int>& aam) {
        unordered_map<long long, int> dabba;

        for (int laddoo : aam) {
            dabba[laddoo]++;
        }

        int jawab = 0;

        if (dabba[1] % 2 == 0) {
            jawab = dabba[1] - 1;
        } else {
            jawab = dabba[1];
        }

        dabba.erase(1);

        for (auto& [kachori, pakoda] : dabba) {
            int ginti = 0;
            long long jalebi = kachori;

            for (; dabba.contains(jalebi) && dabba[jalebi] > 1; jalebi *= jalebi) {
                ginti += 2;
            }

            jawab = max(jawab, ginti + (dabba.contains(jalebi) ? 1 : -1));
        }

        return jawab;
    }
};