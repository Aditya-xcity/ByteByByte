class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ginti = digits.size();
        bool dekha[1000]{};
        int jawab = 0;

        for (int pehla = 0; pehla < ginti; ++pehla) {
            if (digits[pehla] == 0) {
                continue;
            }

            for (int dusra = 0; dusra < ginti; ++dusra) {
                if (dusra == pehla) {
                    continue;
                }

                for (int teesra = 0; teesra < ginti; ++teesra) {
                    if (teesra == pehla || teesra == dusra || digits[teesra] % 2 != 0) {
                        continue;
                    }

                    int sankhya = digits[pehla] * 100 + digits[dusra] * 10 + digits[teesra];

                    if (!dekha[sankhya]) {
                        dekha[sankhya] = true;
                        ++jawab;
                    }
                }
            }
        }

        return jawab;
    }
};