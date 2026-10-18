
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long modJi = 1e9 + 7;
        int ginti = nums.size();

        vector<int> janam(ginti + 2, -1);
        for (int i = 0; i < ginti; ++i)
            janam[nums[i]] = i;

        long long gunaa = 1, akar = 1;

        for (int k = 2; k <= ginti; ++k)
            gunaa = gunaa * k % modJi;

        vector<int> jugaad = {0};

        for (int maan = 1; maan <= ginti + 1; ++maan) {
            while (janam[jugaad.back()] > janam[maan]) {
                jugaad.pop_back();
                akar = akar * (maan - jugaad.back() - 1) % modJi;
            }
            jugaad.push_back(maan);
        }

        return (gunaa * power(akar, modJi - 2, modJi) - 1 + modJi) % modJi;
    }

private:
    long long power(long long adha, long long ghat, long long seema) {
        long long jawab = 1;

        for (adha %= seema; ghat; ghat >>= 1, adha = adha * adha % seema)
            if (ghat & 1)
                jawab = jawab * adha % seema;

        return jawab;
    }
};
