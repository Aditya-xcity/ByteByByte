class Solution {
public:
    int largestInteger(vector<int>& sankhya, int k) {
        int ginti[51] = {0};

        for (auto& x : sankhya)
            ginti[x]++;

        int uttar = -1, n = sankhya.size();

        for (int i = 0; i < n; i++)
            if (k == n || (ginti[sankhya[i]] == 1 && (k == 1 || !i || i == n - 1)))
                uttar = max(uttar, sankhya[i]);

        return uttar;
    }
};