class Solution {
public:
    vector<int> validSequence(string shabdEk, string shabdDo) {
        int lambaiEk = shabdEk.length(), lambaiDo = shabdDo.length();

        vector<int> aakhri(lambaiDo, -1);
        int j = lambaiDo - 1;

        for (int i = lambaiEk - 1; i >= 0; --i) {
            if (j >= 0 && shabdEk[i] == shabdDo[j]) {
                aakhri[j] = i;
                j -= 1;
            }
        }

        vector<int> jawab;
        int chhodna = 0;
        j = 0;

        for (int i = 0; i < lambaiEk; ++i) {
            if (j == lambaiDo)
                break;

            if (shabdEk[i] == shabdDo[j] ||
                (chhodna == 0 &&
                 (j == lambaiDo - 1 || i < aakhri[j + 1]))) {

                chhodna += (shabdEk[i] != shabdDo[j] ? 1 : 0);
                jawab.push_back(i);
                j += 1;
            }
        }

        return j == lambaiDo ? jawab : vector<int>();
    }
};