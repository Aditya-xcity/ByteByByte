
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int seema = 1e9 + 7;
        vector<int> ginti(30, 0);

        for (int sankhya : nums) {
            for (int i = 0; i < 30; i++) {
                if (sankhya & (1 << i)) {
                    ginti[i]++;
                }
            }
        }

        long long yog = 0;
        for (int i = 0; i < k; i++) {
            long long vartaman = 0;

            for (int j = 29; j >= 0; j--) {
                if (ginti[j] > 0) {
                    vartaman |= (1LL << j);
                    ginti[j]--;
                }
            }

            yog = (yog + vartaman * vartaman) % seema;
        }

        return (int)yog;
    }
};
