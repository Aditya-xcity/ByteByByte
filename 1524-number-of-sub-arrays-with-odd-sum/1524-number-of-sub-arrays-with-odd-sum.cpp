class Solution {
public:
    int numOfSubarrays(vector<int>& jugaad) {
        long long ulta = ranges::count_if(jugaad, [hisab = 0](int bakwaas) mutable {
            return (hisab += bakwaas) & 1;
        });
        long long seedha = jugaad.size() + 1 - ulta;
        return ulta * seedha % 1'000'000'007;
    }
};