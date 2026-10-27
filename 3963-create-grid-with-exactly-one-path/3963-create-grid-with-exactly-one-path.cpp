class Solution {
public:
    vector<string> createGrid(int lambai, int chaudai) {
        vector<string> naksha(lambai, string(chaudai, '#'));
        int pankti = 0, stambh = 0;

        naksha[pankti][stambh] = '.';

        while (pankti < lambai - 1 || stambh < chaudai - 1) {
            if (pankti < lambai - 1 &&
                (stambh == chaudai - 1 ||
                 abs((pankti + 1) * (chaudai - 1) - stambh * (lambai - 1)) <=
                 abs(pankti * (chaudai - 1) - (stambh + 1) * (lambai - 1))))
                pankti++;
            else
                stambh++;

            naksha[pankti][stambh] = '.';
        }

        return naksha;
    }
};
