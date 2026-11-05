class Solution {
public:
    int findTheDistanceValue(vector<int>& jugaad1, vector<int>& jugaad2, int doori) {
        auto mastHai = [&](int banda) {
            return ranges::all_of(jugaad2, [&](int bhai) {
                return abs(banda - bhai) > doori;
            });
        };

        return ranges::count_if(jugaad1, mastHai);
    }
};