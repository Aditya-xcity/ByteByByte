class Solution {
public:
    int uniqueXorTriplets(vector<int>& aam) {
        size_t bandar = aam.size();
        return 1 << (bit_width(bandar) - 3 / (bandar + 1));
    }
};