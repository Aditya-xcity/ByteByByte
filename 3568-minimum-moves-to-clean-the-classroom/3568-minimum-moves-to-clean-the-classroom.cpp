class Solution {
public:
    int minMoves(vector<string>& kaksha, int urja) {
        int pankti = kaksha.size();
        int stambh = kaksha[0].size();

        vector<vector<int>> pehchan(pankti, vector<int>(stambh, -1));

        int ginti = 0;
        int shuruPankti = 0, shuruStambh = 0;

        for (int panktiNo = 0; panktiNo < pankti; panktiNo++) {
            for (int stambhNo = 0; stambhNo < stambh; stambhNo++) {
                if (kaksha[panktiNo][stambhNo] == 'S') {
                    shuruPankti = panktiNo;
                    shuruStambh = stambhNo;
                } 
                else if (kaksha[panktiNo][stambhNo] == 'L') {
                    pehchan[panktiNo][stambhNo] = ginti++;
                }
            }
        }

        if (ginti == 0)
            return 0;

        int pooraMask = (1 << ginti) - 1;

        vector<vector<vector<int>>> sabseAchha(
            pankti,
            vector<vector<int>>(stambh, vector<int>(1 << ginti, -1))
        );

        struct Haalat {
            int pankti, stambh, mask, urja, chaal;
        };

        queue<Haalat> line;

        sabseAchha[shuruPankti][shuruStambh][0] = urja;
        line.push({shuruPankti, shuruStambh, 0, urja, 0});

        int panktiBadlav[] = {-1, 1, 0, 0};
        int stambhBadlav[] = {0, 0, -1, 1};

        while (!line.empty()) {
            Haalat vartaman = line.front();
            line.pop();

            for (int disha = 0; disha < 4; disha++) {
                int nayiPankti = vartaman.pankti + panktiBadlav[disha];
                int nayaStambh = vartaman.stambh + stambhBadlav[disha];

                if (nayiPankti < 0 || nayiPankti >= pankti ||
                    nayaStambh < 0 || nayaStambh >= stambh)
                    continue;

                if (kaksha[nayiPankti][nayaStambh] == 'X')
                    continue;

                int nayiUrja = vartaman.urja - 1;

                if (nayiUrja < 0)
                    continue;

                int nayaMask = vartaman.mask;

                if (kaksha[nayiPankti][nayaStambh] == 'R') {
                    nayiUrja = urja;
                }

                if (kaksha[nayiPankti][nayaStambh] == 'L') {
                    nayaMask |= (1 << pehchan[nayiPankti][nayaStambh]);
                }

                if (nayaMask == pooraMask) {
                    return vartaman.chaal + 1;
                }

                if (nayiUrja <= sabseAchha[nayiPankti][nayaStambh][nayaMask])
                    continue;

                sabseAchha[nayiPankti][nayaStambh][nayaMask] = nayiUrja;

                line.push({
                    nayiPankti,
                    nayaStambh,
                    nayaMask,
                    nayiUrja,
                    vartaman.chaal + 1
                });
            }
        }

        return -1;
    }
};