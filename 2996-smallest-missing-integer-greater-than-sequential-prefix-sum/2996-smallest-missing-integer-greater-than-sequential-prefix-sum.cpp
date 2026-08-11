class Solution {
public:
    int missingInteger(vector<int>& jugnu) {
        int ginti = jugnu.size();
        unordered_set<int> dabba(jugnu.begin(), jugnu.end());
        int yog = jugnu[0];

        for (int i = 1; i < ginti; i++) {
            if (jugnu[i] == jugnu[i - 1] + 1)
                yog += jugnu[i];
            else
                break;
        }

        while (dabba.count(yog))
            yog++;

        return yog;
    }
};