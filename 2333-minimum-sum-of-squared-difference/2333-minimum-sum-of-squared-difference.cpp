
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> aloo(100001, 0);
        long long paisa = (long long)k1 + k2, yog = 0;
        int bada = 0;

        // Step 1: count the differences
        for (int i = 0; i < nums1.size(); i++) {
            int chotu = abs(nums1[i] - nums2[i]);
            aloo[chotu]++;
            yog += chotu;
            bada = max(bada, chotu);
        }

        // Enough budget -> every difference becomes 0
        if (yog <= paisa) return 0;

        // Step 2: reduce the biggest differences
        for (int i = bada; i > 0 && paisa > 0; i--) {
            long long jugaad = min(paisa, (long long)aloo[i]);
            aloo[i] -= jugaad;
            aloo[i - 1] += jugaad;
            paisa -= jugaad;
        }

        // Step 3: add up the squares
        long long jawab = 0;
        for (int i = 0; i <= bada; i++)
            jawab += (long long)i * i * aloo[i];

        return jawab;
    }
};
