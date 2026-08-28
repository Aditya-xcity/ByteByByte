class Solution {
public:
    string lexPalindromicPermutation(string naam, string lakshya) {
        int lambai = naam.length();

        if (lambai == 1) {
            return naam > lakshya ? naam : "";
        }

        vector<int> ginti(26, 0);

        for (char akshar : naam) {
            ginti[akshar - 'a']++;
        }

        string visham = "";

        for (int suchak = 0; suchak < 26; suchak++) {
            if (ginti[suchak] % 2 == 1) {
                if (visham != "") {
                    return "";
                }
                visham = string(1, 'a' + suchak);
            }

            ginti[suchak] /= 2;
        }

        string aage = "";

        auto jaanch = [&](char akshar) -> bool {
            string baaya = aage;
            baaya.push_back(akshar);

            for (int suchak = 25; suchak >= 0; suchak--) {
                baaya.append(ginti[suchak], 'a' + suchak);
            }

            string pratibimb = baaya + visham;

            string ulta = baaya;
            reverse(ulta.begin(), ulta.end());

            pratibimb += ulta;

            return pratibimb > lakshya;
        };

        for (int charan = 0; charan < lambai / 2; charan++) {
            bool mila = false;

            for (int kram = 0; kram < 26; kram++) {
                if (ginti[kram] == 0) {
                    continue;
                }

                ginti[kram]--;

                if (jaanch('a' + kram)) {
                    aage.push_back('a' + kram);
                    mila = true;
                    break;
                } else {
                    ginti[kram]++;
                }
            }

            if (!mila) {
                return "";
            }

            if (aage[charan] > lakshya[charan]) {
                string baaya = aage;

                for (int kram = 0; kram < 26; kram++) {
                    baaya.append(ginti[kram], 'a' + kram);
                }

                string pratibimb = baaya + visham;

                string ulta = baaya;
                reverse(ulta.begin(), ulta.end());

                pratibimb += ulta;

                return pratibimb;
            }
        }

        string uttar = aage + visham;

        string ultaAage = aage;
        reverse(ultaAage.begin(), ultaAage.end());

        uttar += ultaAage;

        return uttar;
    }
};