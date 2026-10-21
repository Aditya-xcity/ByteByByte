class Solution {
public:
    int minOperations(string shabd) {
        if (is_sorted(shabd.begin(), shabd.end())) return 0;
        if (shabd.size() == 2) return -1;

        auto [chhota, bada] = minmax_element(shabd.begin() + 1, shabd.end() - 1);

        if (shabd[0] <= min(*chhota, shabd.back()) ||
            max(shabd[0], *bada) <= shabd.back()) return 1;

        return shabd.back() < *chhota && *bada < shabd[0] ? 3 : 2;
    }
};