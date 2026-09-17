class Solution {
public:
    int minSumOfLengths(vector<int>& A, int k) {
        int lambai = A.size();
        int jawab = lambai + 1, yog = 0, baaya = 0;

        vector<int> yaad(lambai + 1, lambai);

        for (int daaya = 0; daaya < lambai; daaya++) {
            yog += A[daaya];

            while (yog > k)
                yog -= A[baaya++];

            yaad[daaya + 1] = yaad[daaya];

            if (yog == k) {
                jawab = min(jawab, daaya - baaya + 1 + yaad[baaya]);
                yaad[daaya + 1] = min(yaad[daaya], daaya - baaya + 1);
            }
        }

        return jawab == lambai + 1 ? -1 : jawab;
    }
};