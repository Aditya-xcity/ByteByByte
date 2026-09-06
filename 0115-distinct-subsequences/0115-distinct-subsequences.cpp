class Solution {
public:
    int numDistinct(string s, string t) {
        int lambai_s = s.size();
        int lambai_t = t.size();

        if (lambai_s < lambai_t) {
            return 0;
        }

        vector<vector<unsigned long long>> jugaad(
            lambai_s + 1,
            vector<unsigned long long>(lambai_t + 1, 0)
        );

        for (int chhora = 0; chhora <= lambai_s; chhora++) {
            jugaad[chhora][lambai_t] = 1;
        }

        for (int chhora = lambai_s - 1; chhora >= 0; chhora--) {
            for (int chhori = lambai_t - 1; chhori >= 0; chhori--) {

                if (s[chhora] == t[chhori]) {
                    jugaad[chhora][chhori] =
                        jugaad[chhora + 1][chhori + 1]
                        + jugaad[chhora + 1][chhori];
                }
                else {
                    jugaad[chhora][chhori] =
                        jugaad[chhora + 1][chhori];
                }
            }
        }

        return jugaad[0][0];
    }
};