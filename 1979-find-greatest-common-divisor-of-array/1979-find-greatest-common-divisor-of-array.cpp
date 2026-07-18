class Solution {
public:
    int findGCD(vector<int>& samuh) {
        int bada = *max_element(samuh.begin(), samuh.end());
        int chhota = *min_element(samuh.begin(), samuh.end());
        return gcd(bada, chhota);
    }
};