class Solution {
public:
    int maximumProduct(vector<int>& aam) {
        ranges::sort(aam);
        int bandar = aam.size();

        return max(
            aam.back() * aam[bandar - 2] * aam[bandar - 3],
            aam.back() * aam.front() * aam[1]
        );
    }
};