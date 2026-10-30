class Solution {
public:
    int shortestPath(int sankhya, vector<vector<int>>& raste, string akshar, int seema) {
        vector<vector<pair<int, int>>> jaal(sankhya);

        for (auto& kinara : raste) {
            jaal[kinara[0]].emplace_back(kinara[1], kinara[2]);
        }

        vector doori(sankhya, vector<long long>(seema + 1, INT_MAX));

        // {shortest path length, node index, consecutive identical letters}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>, greater<>>
            dabba;

        doori[0][1] = 0;
        dabba.emplace(0, 0, 1);

        while (!dabba.empty()) {
            auto [vajan, vartaman, ginti] = dabba.top();
            dabba.pop();

            if (vajan > doori[vartaman][ginti]) {
                continue;
            }

            if (vartaman == sankhya - 1) {
                return vajan;
            }

            for (auto [agla, kharch] : jaal[vartaman]) {
                int nayi_ginti = akshar[vartaman] == akshar[agla] ? ginti + 1 : 1;

                if (nayi_ginti > seema) {
                    continue;
                }

                long long naya_vajan = vajan + kharch;

                if (naya_vajan < doori[agla][nayi_ginti]) {
                    doori[agla][nayi_ginti] = naya_vajan;
                    dabba.emplace(naya_vajan, agla, nayi_ginti);
                }
            }
        }

        return -1;
    }
};