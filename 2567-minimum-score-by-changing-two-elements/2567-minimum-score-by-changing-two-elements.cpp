class Solution {
public:
    int minimizeSum(vector<int>& badal) {
        array<int, 3> chotu, motu;
        ranges::partial_sort_copy(badal, chotu);
        ranges::partial_sort_copy(badal, motu, greater{});
        return min({motu[0] - chotu[2], motu[1] - chotu[1], motu[2] - chotu[0]});
    }
};