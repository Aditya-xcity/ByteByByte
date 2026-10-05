class Solution {
public:
    int scoreOfParentheses(string chappal) {
        return Ginti(chappal, 0, chappal.length());
    }

private:
    int Ginti(const string& chappal, int shuru, int ant) {
        int jawab = 0, santulan = 0;

        for (int g = shuru; g < ant; ++g) {
            santulan += (chappal[g] == '(' ? 1 : -1);

            if (santulan == 0) {
                if (g - shuru == 1) {
                    jawab++;
                } else {
                    jawab += 2 * Ginti(chappal, shuru + 1, g);
                }

                shuru = g + 1;
            }
        }

        return jawab;
    }
};