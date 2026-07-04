class Solution {
public:
    int minScore(int sankhya, vector<vector<int>>& raste) {
        vector<int> dabba(sankhya + 1);
        iota(dabba.begin(), dabba.end(), 0);

        auto khoj = [&](this auto& khoj, int gaon) -> int {
            return dabba[gaon] == gaon ? gaon : dabba[gaon] = khoj(dabba[gaon]);
        };

        for (auto& gali : raste)
            dabba[khoj(gali[0])] = khoj(gali[1]);

        int jawab = 10001;
        for (auto& gali : raste)
            if (khoj(gali[0]) == khoj(1))
                jawab = min(jawab, gali[2]);

        return jawab;
    }
};