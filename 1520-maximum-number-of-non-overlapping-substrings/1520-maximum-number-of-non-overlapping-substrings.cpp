class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int ginti[26] = {};
        int pehla[26], aakhri[26];

        fill(pehla, pehla + 26, -1);
        fill(aakhri, aakhri + 26, -1);

        vector<int> kram;

        for (int i = 0; i < s.size(); i++) {
            int akshar = s[i] - 'a';

            if (ginti[akshar] == 0) {
                pehla[akshar] = i;
                kram.push_back(akshar);
            }

            ginti[akshar]++;
            aakhri[akshar] = i;
        }

        vector<string> jawab;
        deque<array<int, 3>> dabba;

        for (int akshar : kram) {
            dabba.push_front({pehla[akshar], aakhri[akshar], ginti[akshar]});

            int baaya = INT_MAX;
            int daaya = INT_MIN;
            int kul = 0;

            for (auto& cheez : dabba) {
                kul += cheez[2];
                baaya = min(baaya, cheez[0]);
                daaya = max(daaya, cheez[1]);

                if (kul == daaya - baaya + 1) {
                    break;
                }
            }

            if (kul == daaya - baaya + 1) {
                jawab.push_back(s.substr(baaya, daaya - baaya + 1));
                dabba.clear();
            }
        }

        return jawab;
    }
};