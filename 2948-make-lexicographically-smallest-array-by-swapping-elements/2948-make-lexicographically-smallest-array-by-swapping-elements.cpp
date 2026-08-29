class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
        vector<int> sorted = A;
        ranges::sort(sorted);

        vector<vector<int>> samuh;
        unordered_map<int, int> naksha;
        int pehchan = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                samuh.push_back({});
                pehchan++;
            }
            samuh[pehchan].push_back(sorted[i]);
            naksha[sorted[i]] = pehchan;
        }

        vector<int> ginti(samuh.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            int vartaman = naksha[A[i]];
            A[i] = samuh[vartaman][ginti[vartaman]];
            ginti[vartaman]++;
        }

        return A;
    }
};