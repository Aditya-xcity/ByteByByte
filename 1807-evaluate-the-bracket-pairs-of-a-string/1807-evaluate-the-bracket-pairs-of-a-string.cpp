class Solution {
public:
    string evaluate(string vaakya, auto& suchi) {
        unordered_map<string, string> naksha;

        for (auto& vastu : suchi)
            naksha[vastu[0]] = vastu[1];

        string uttar;

        for (int i = 0; i < vaakya.size(); ++i) {
            if (vaakya[i] == '(') {
                int j = vaakya.find(")", i + 1);
                auto shabd = vaakya.substr(i + 1, j - i - 1);

                uttar += naksha.count(shabd) ? naksha[shabd] : "?";
                i = j;
            } else {
                uttar += vaakya[i];
            }
        }

        return uttar;
    }
};