class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int duniya = parent.size();
        vector<vector<int>> bacche(duniya);

        for (int banda = 1; banda < duniya; ++banda)
            bacche[parent[banda]].push_back(banda);

        vector<int> hisaab(duniya, 1), uparwala(duniya);

        array<int, 26> pichla;
        pichla.fill(-1);

        vector<int> dabba{0};

        while (!dabba.empty()) {
            int banda = dabba.back();
            dabba.pop_back();

            if (banda >= 0) {
                int akshar = s[banda] - 'a';

                uparwala[banda] = pichla[akshar];
                pichla[akshar] = banda;

                dabba.push_back(~banda);

                dabba.insert(
                    dabba.end(),
                    bacche[banda].begin(),
                    bacche[banda].end()
                );
            } else {
                banda = ~banda;

                pichla[s[banda] - 'a'] = uparwala[banda];

                if (banda)
                    hisaab[uparwala[banda] >= 0
                        ? uparwala[banda]
                        : parent[banda]] += hisaab[banda];
            }
        }

        return hisaab;
    }
};

inline auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();