class Solution {
public:
    vector<long long> resultArray(vector<int>& chintu, int k) {
        vector<long long> jawab(k);
        int ginti[5] = {0};

        for (auto& sankhya : chintu) {
            sankhya %= k;
            int vartaman[5] = {0};

            vartaman[sankhya] = 1;

            for (int x = 0; x < k; x++)
                vartaman[x * sankhya % k] += ginti[x];

            for (int x = 0; x < k; x++) {
                ginti[x] = vartaman[x];
                jawab[x] += ginti[x];
            }
        }

        return jawab;
    }
};