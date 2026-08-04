class Solution {
public:
    static vector<int> findMissingElements(vector<int>& dabba) {
        bitset<101> aam = 0;
        int chotu = 101, bada = 0;

        for (int laddu : dabba) {
            aam[laddu] = 1;
            chotu = min(laddu, chotu);
            bada = max(laddu, bada);
        }

        vector<int> jalebi;

        for (int kela = chotu + 1; kela < bada; kela++)
            if (!aam[kela])
                jalebi.push_back(kela);

        return jalebi;
    }
};