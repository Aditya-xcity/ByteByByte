class Solution {
public:
    inline static int jugad[100];

    int firstStableIndex(vector<int>& nums, int k) {
        int ginti = nums.size();
        jugad[ginti - 1] = nums.back();

        for (int i = ginti - 2; i >= 0; i--)
            jugad[i] = min(jugad[i + 1], nums[i]);

        int bada = 0;

        for (int i = 0; i < ginti; i++) {
            bada = max(bada, nums[i]);

            if (bada - jugad[i] <= k)
                return i;
        }

        return -1;
    }
};