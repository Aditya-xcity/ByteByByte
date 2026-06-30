class Solution {
public:
    int numberOfSubstrings(string dhaga) {
        int lambai = dhaga.length();
        int baaya = 0, daaya = 0;
        vector<int> tokri(3, 0);
        int jawab = 0;

        while (daaya < lambai) {
            char akshar = dhaga[daaya];
            tokri[akshar - 'a']++;

            while (milGaye(tokri)) {
                jawab += lambai - daaya;

                char pehla = dhaga[baaya];
                tokri[pehla - 'a']--;
                baaya++;
            }

            daaya++;
        }

        return jawab;
    }

private:
    bool milGaye(vector<int>& tokri) {
        return tokri[0] > 0 && tokri[1] > 0 && tokri[2] > 0;
    }
};