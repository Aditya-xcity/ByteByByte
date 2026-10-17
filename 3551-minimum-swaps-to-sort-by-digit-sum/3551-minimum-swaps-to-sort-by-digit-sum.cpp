
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ginti = nums.size();
        vector<int> ankJod(ginti);

        for (int i = 0; i < ginti; i++) {
            int sankhya = nums[i], jod = 0;

            while (sankhya > 0) {
                jod += sankhya % 10;
                sankhya /= 10;
            }

            ankJod[i] = jod;
        }

        vector<int> jagah(ginti);
        iota(jagah.begin(), jagah.end(), 0);

        sort(jagah.begin(), jagah.end(), [&](int pehla, int dusra) {
            if (ankJod[pehla] != ankJod[dusra]) {
                return ankJod[pehla] < ankJod[dusra];
            }

            return nums[pehla] < nums[dusra];
        });

        vector<int> nayiJagah(ginti);

        for (int sthan = 0; sthan < ginti; sthan++) {
            nayiJagah[jagah[sthan]] = sthan;
        }

        vector<int> dekha(ginti);
        int chakr = 0;

        for (int i = 0; i < ginti; i++) {
            if (!dekha[i]) {
                chakr++;
                int agla = i;

                while (!dekha[agla]) {
                    dekha[agla] = true;
                    agla = nayiJagah[agla];
                }
            }
        }

        return ginti - chakr;
    }
};
