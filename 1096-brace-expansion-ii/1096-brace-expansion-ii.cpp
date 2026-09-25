class Solution {
public:
    vector<char> kriya;
    vector<vector<string>> dabba;

    void kaam() {
        int pehla = dabba.size() - 2;
        int dusra = dabba.size() - 1;

        if (kriya.back() == '+') {
            // Union
            dabba[pehla].reserve(dabba[pehla].size() + dabba[dusra].size());
            dabba[pehla].insert(
                dabba[pehla].end(),
                dabba[dusra].begin(),
                dabba[dusra].end()
            );
        }
        else {
            // Concatenation
            vector<string> agla;

            agla.reserve(dabba[pehla].size() * dabba[dusra].size());

            for (const auto& baaya : dabba[pehla]) {
                for (const auto& daaya : dabba[dusra]) {
                    agla.push_back(baaya + daaya);
                }
            }

            dabba[pehla] = move(agla);
        }

        kriya.pop_back();
        dabba.pop_back();
    }

    vector<string> braceExpansionII(string& abhivyakti) {
        const int lambai = abhivyakti.size();

        kriya.reserve(lambai);

        char pichhla = '@', vartamaan;

        for (int i = 0; i < lambai; i++, pichhla = vartamaan) {
            vartamaan = abhivyakti[i];

            switch (vartamaan) {

            case ',':
                while (!kriya.empty() && kriya.back() != '{')
                    kaam();

                kriya.push_back('+');
                break;

            case '{':
                if (pichhla == '}' || isalpha(pichhla))
                    kriya.push_back('*');

                kriya.push_back('{');
                break;

            case '}':
                while (!kriya.empty() && kriya.back() != '{')
                    kaam();

                kriya.pop_back(); // Matching '{' hatao
                break;

            default:
                if (pichhla == '}')
                    kriya.push_back('*');

                string tukda;

                for (; i < lambai && isalpha(abhivyakti[i]); i++)
                    tukda += abhivyakti[i];

                dabba.push_back({tukda});

                i--;
                vartamaan = abhivyakti[i];
            }
        }

        while (!kriya.empty())
            kaam();

        auto uttar = dabba.front();

        sort(uttar.begin(), uttar.end());

        uttar.erase(
            unique(uttar.begin(), uttar.end()),
            uttar.end()
        );

        return uttar;
    }
};

auto aarambh = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 'c';
}();