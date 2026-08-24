class Solution {
public:
    int stoneGameVIII(vector<int>& pathar) {
        int ginti = pathar.size();

        for (int i = 1; i < ginti; i++)
            pathar[i] += pathar[i - 1];

        int uttar = pathar.back();

        for (int i = ginti - 2; i > 0; i--)
            uttar = max(uttar, pathar[i] - uttar);

        return uttar;
    }
};