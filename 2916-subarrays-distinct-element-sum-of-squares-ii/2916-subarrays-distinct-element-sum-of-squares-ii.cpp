
class Solution {
public:
    int sumCounts(vector<int>& sankhya) {
        const long long seema = 1e9 + 7;
        int lambai = sankhya.size();

        vector<long long> ginti(lambai + 1), yog(lambai + 1);
        unordered_map<int, int> aakhri;

        long long jawab = 0;

        for (int daaya = 0; daaya < lambai; daaya++) {
            int pichhla = aakhri.count(sankhya[daaya])
                ? aakhri[sankhya[daaya]]
                : -1;

            long long gin = 0, jod = 0;

            for (int dabba = lambai - pichhla - 1;
                 dabba > 0;
                 dabba -= dabba & -dabba) {
                gin += ginti[dabba];
                jod += yog[dabba];
            }

            long long badhotri =
                (long long)(daaya - pichhla) * (daaya - pichhla)
                - 2 * (jod - pichhla * gin);

            jawab = (jawab + (lambai - daaya) * badhotri) % seema;

            for (int dabba = lambai - pichhla;
                 dabba <= lambai;
                 dabba += dabba & -dabba) {
                ginti[dabba]++;
                yog[dabba] += pichhla;
            }

            aakhri[sankhya[daaya]] = daaya;
        }

        return jawab;
    }
};
