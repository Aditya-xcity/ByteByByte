class Solution {
public:
    vector<int> targetIndices(vector<int>& sankhya, int lakshya) {
        int ginti = sankhya.size();
        sort(sankhya.begin(), sankhya.end());
        vector<int> jawab;

        for (int i = 0; i < ginti; ++i) {
            if (sankhya[i] == lakshya) {
                jawab.push_back(i);
            }
        }
        return jawab;
    }
};