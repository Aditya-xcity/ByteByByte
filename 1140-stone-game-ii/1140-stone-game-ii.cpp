class Solution {
    int khoj(int jagah, int seema, vector<int>& dher, unordered_map<int, int>& yaad) {
        int sankhya = dher.size();

        if (jagah + seema * 2 >= sankhya)
            return dher[jagah];

        int chaabi = (jagah << 8) | seema;

        if (yaad.count(chaabi))
            return yaad[chaabi];

        int jawab = 2000000000;

        for (int kitna = 1; kitna <= seema * 2; kitna++)
            jawab = min(jawab, khoj(jagah + kitna, max(seema, kitna), dher, yaad));

        yaad[chaabi] = dher[jagah] - jawab;

        return yaad[chaabi];
    }

public:
    int stoneGameII(vector<int>& dher) {
        int sankhya = dher.size();

        for (int jagah = sankhya - 2; jagah >= 0; jagah--)
            dher[jagah] += dher[jagah + 1];

        unordered_map<int, int> yaad;

        return khoj(0, 1, dher, yaad);
    }
};