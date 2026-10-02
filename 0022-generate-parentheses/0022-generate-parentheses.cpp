class Solution {
public:
    vector<string> generateParenthesis(int ginti) {
        if (ginti-- == 1) return {"()"};

        vector<string> jawab;

        auto jugaad = [&](auto& khud, int khula, int band, string vakya) -> void {
            if (khula == 0 && band == 0) {
                jawab.push_back(vakya + ")");
                return;
            }

            if (khula > 0)
                khud(khud, khula - 1, band, vakya + "(");

            if (band >= khula)
                khud(khud, khula, band - 1, vakya + ")");
        };

        jugaad(jugaad, ginti, ginti, "(");

        return jawab;
    }
};