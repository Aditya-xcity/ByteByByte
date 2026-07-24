class Solution {
public:
    int uniqueXorTriplets(vector<int>& aam) {
        const int seema = 2048;

        vector<bool> jugal(seema, false);
        vector<bool> teeka(seema, false);

        int ginti = aam.size();

        for (int raju = 0; raju < ginti; raju++) {
            for (int mohan = raju; mohan < ginti; mohan++) {
                jugal[aam[raju] ^ aam[mohan]] = true;
            }
        }

        for (int rang = 0; rang < seema; rang++) {
            if (!jugal[rang]) continue;
            for (int laddoo : aam) {
                teeka[rang ^ laddoo] = true;
            }
        }

        int hisaab = 0;
        for (int babu = 0; babu < seema; babu++) {
            if (teeka[babu]) hisaab++;
        }

        return hisaab;
    }
};