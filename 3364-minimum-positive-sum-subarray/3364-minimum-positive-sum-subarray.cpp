class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int kitne = nums.size();
        int jawab = INT_MAX;

        for (int shuru = 0; shuru < kitne; shuru++) {
            int jod = 0;

            for (int aage = shuru; aage < kitne; aage++) {
                jod += nums[aage];
                int lambai = aage - shuru + 1;

                if (lambai >= l && lambai <= r && jod > 0) {
                    jawab = min(jawab, jod);
                }
            }
        }

        return jawab == INT_MAX ? -1 : jawab;
    }
};