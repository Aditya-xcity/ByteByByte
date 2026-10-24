class Solution {
public:
    int countDaysTogether(string aaneAlice, string jaaneAlice,
                          string aaneBob, string jaaneBob) {

        vector<int> mahine = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

        auto dinGino = [&](string tarikh) {
            int mahina = stoi(tarikh.substr(0, 2));
            int din = stoi(tarikh.substr(3));

            for (int i = 0; i < mahina - 1; i++) {
                din += mahine[i];
            }

            return din;
        };

        int shuruAlice = dinGino(aaneAlice);
        int khatamAlice = dinGino(jaaneAlice);
        int shuruBob = dinGino(aaneBob);
        int khatamBob = dinGino(jaaneBob);

        int shuru = max(shuruAlice, shuruBob);
        int khatam = min(khatamAlice, khatamBob);

        return max(0, khatam - shuru + 1);
    }
};