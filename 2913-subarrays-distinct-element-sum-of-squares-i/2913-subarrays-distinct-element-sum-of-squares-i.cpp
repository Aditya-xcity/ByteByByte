class Solution {
public:
    int sumCounts(vector<int>& ginti) {
        int lambai = ginti.size(), jawab = 0;
        for (int i = 0; i < lambai; i++) {
            unordered_set<int> alag;
            for (int j = i; j < lambai; j++) {
                alag.insert(ginti[j]);
                jawab += alag.size() * alag.size();
            }
        }
        return jawab;
    }
};