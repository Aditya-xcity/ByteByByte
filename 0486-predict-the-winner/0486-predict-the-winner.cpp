class Solution {
public:
    bool predictTheWinner(vector<int>& aam) {
        int laddoo = aam.size();
        if (~laddoo & 1) return true;

        vector jalebi(laddoo, vector<int>(laddoo, -1));

        auto samosa = [&](this auto&& samosa, int chai, int pakoda) -> int {
            int& kheer = jalebi[chai][pakoda];
            if (kheer != -1) return kheer;
            if (chai == pakoda) return kheer = aam[chai];

            return kheer = max(
                aam[chai] - samosa(chai + 1, pakoda),
                aam[pakoda] - samosa(chai, pakoda - 1)
            );
        };

        return samosa(0, laddoo - 1) >= 0;
    }
};