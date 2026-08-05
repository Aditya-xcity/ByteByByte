constexpr int MAXN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int shuru, vector<vector<int>>& raaste) {
        vector<vector<int>> ped(n);
        vector<int> darja(n, 0);

        bitset<MAXN> shakki;

        for (const auto& rasta : raaste) {
            ped[rasta[0]].push_back(rasta[1]);
            darja[rasta[1]]++;
        }

        queue<int> dabba;
        dabba.push(shuru);

        shakki.set(shuru);

        while (!dabba.empty()) {
            int gaon = dabba.front();
            dabba.pop();

            for (int padosi : ped[gaon]) {
                darja[padosi]--;

                if (!shakki.test(padosi)) {
                    dabba.push(padosi);
                    shakki.set(padosi);
                }
            }
        }

        bool hataSakte = true;
        vector<int> bacheHue;

        for (int i = 0; i < n; i++) {
            if (shakki.test(i) && darja[i] > 0) {
                hataSakte = false;
                break;
            } else if (!shakki.test(i)) {
                bacheHue.push_back(i);
            }
        }

        if (!hataSakte) {
            vector<int> sab(n);
            iota(sab.begin(), sab.end(), 0);
            return sab;
        }

        return bacheHue;
    }
};