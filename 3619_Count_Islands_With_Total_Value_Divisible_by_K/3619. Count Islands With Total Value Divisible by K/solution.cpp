#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int pankti = grid.size(), stambh = grid[0].size();
        const int disha[5] = {-1, 0, 1, 0, -1};

        function<long long(int, int)> khojo = [&](int i, int j) -> long long {
            long long jama = grid[i][j];
            grid[i][j] = 0;

            for (int ghum = 0; ghum < 4; ++ghum) {
                int agla = i + disha[ghum];
                int bagla = j + disha[ghum + 1];

                if (agla >= 0 && agla < pankti &&
                    bagla >= 0 && bagla < stambh &&
                    grid[agla][bagla] > 0) {
                    jama += khojo(agla, bagla);
                }
            }

            return jama;
        };

        int ginti = 0;

        for (int i = 0; i < pankti; ++i) {
            for (int j = 0; j < stambh; ++j) {
                if (grid[i][j] > 0 && khojo(i, j) % k == 0) {
                    ++ginti;
                }
            }
        }

        return ginti;
    }
};
