class Solution {
private:
    long long jugaad(long long aam, long long kela, long long laddoo) {
        long long paisa = 1;
        kela = std::min(kela, aam - kela);

        for (long long chai = 1; chai <= kela; chai++) {
            paisa = paisa * (aam - chai + 1) / chai;
            if (paisa > laddoo) {
                return laddoo + 1;
            }
        }
        return paisa;
    }

public:
    std::string smallestPalindrome(std::string mithai, long long laddoo) {
        int aadha = mithai.length() / 2;
        std::vector<int> dabba(26, 0);

        for (int bandar = 0; bandar < aadha; bandar++) {
            dabba[mithai[bandar] - 'a']++;
        }

        auto hisaab = [&](int bacha) {
            long long tareeka = 1;
            for (int golgappa = 0; golgappa < 26; golgappa++) {
                if (dabba[golgappa] == 0) {
                    continue;
                }

                tareeka *= jugaad(bacha, dabba[golgappa], laddoo);
                if (tareeka > laddoo) {
                    break;
                }
                bacha -= dabba[golgappa];
            }
            return tareeka;
        };

        std::string ladoo = "";
        long long shuruaat = 1;

        for (int jagah = 0; jagah < aadha; jagah++) {
            for (int papad = 0; papad < 26; papad++) {
                if (dabba[papad] == 0) {
                    continue;
                }

                dabba[papad]--;

                long long mauka = hisaab(aadha - jagah - 1);
                if (shuruaat + mauka > laddoo) {
                    ladoo += (char)(papad + 'a');
                    break;
                }

                dabba[papad]++;
                shuruaat += mauka;
            }
        }

        if (ladoo.length() < aadha) {
            return "";
        }

        std::string beech =
            mithai.length() % 2 ? std::string(1, mithai[aadha]) : "";

        std::string ulta = ladoo;
        std::reverse(ulta.begin(), ulta.end());

        return ladoo + beech + ulta;
    }
};