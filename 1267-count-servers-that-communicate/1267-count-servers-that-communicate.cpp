class Solution {
public:
    int countServers(vector<vector<int>>& dabba) {
        const int kitniLine = dabba.size(), kitneKhambhe = dabba[0].size();

        vector<int> gali(kitniLine), mohalla(kitneKhambhe);

        for (int chotu = 0; chotu < kitniLine; ++chotu)
            for (int motu = 0; motu < kitneKhambhe; ++motu) {
                gali[chotu] += dabba[chotu][motu];
                mohalla[motu] += dabba[chotu][motu];
            }

        int jugaad = 0;

        for (int chotu = 0; chotu < kitniLine; ++chotu)
            for (int motu = 0; motu < kitneKhambhe; ++motu)
                if (dabba[chotu][motu] && gali[chotu] + mohalla[motu] > 2)
                    ++jugaad;

        return jugaad;
    }
};