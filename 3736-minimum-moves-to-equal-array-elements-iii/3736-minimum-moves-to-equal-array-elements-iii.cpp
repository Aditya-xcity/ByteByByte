
class Solution {
public:
    int minMoves(vector<int>& jugaad) {
        long long int paisa = 0;

        for (auto chintu : jugaad)
            paisa += chintu;

        int sabseBadaDon = *max_element(jugaad.begin(), jugaad.end());

        return jugaad.size() * sabseBadaDon - paisa;
    }
};
