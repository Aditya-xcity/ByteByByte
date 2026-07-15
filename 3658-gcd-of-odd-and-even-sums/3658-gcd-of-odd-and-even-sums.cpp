class Solution {
public:
    int gcd(int aam, int imli) {
        return imli == 0 ? aam : gcd(imli, aam % imli);
    }

    int gcdOfOddEvenSums(int jalebi) {
        return gcd(jalebi * jalebi, jalebi * (jalebi + 1));
    }
};