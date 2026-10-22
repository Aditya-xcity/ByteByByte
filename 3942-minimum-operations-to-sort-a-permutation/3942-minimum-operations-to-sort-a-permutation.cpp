class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ginti = nums.size();
        int modna = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto gol = [&](int kadam) {
            return nums[(modna + kadam) % ginti];
        };

        bool seedha = true, ulta = true;

        for (int kadam = 0; kadam < ginti; kadam++) {
            if (gol(kadam) != kadam)
                seedha = false;

            if (gol(kadam) != (ginti - kadam) % ginti)
                ulta = false;
        }

        if (seedha)
            return min(modna, ginti - modna + 2);

        if (ulta)
            return min(modna + 2, ginti - modna);

        return -1;
    }
};