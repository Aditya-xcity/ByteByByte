class Solution {
    struct Node {
        Node* bachche[26]{};
        Node* pita{};
        Node* rasta{};
        int ginti = 0;
    };

    static constexpr int seema = 10005;

public:
    int numOfStrings(vector<string>& naksha, string shabd) {
        Node* jad = new Node();

        for (auto& tukda : naksha) {
            Node* safar = jad;

            for (int i = 0; i < tukda.size(); i++) {
                int akshar = tukda[i] - 97;

                if (!safar->bachche[akshar])
                    safar->bachche[akshar] = new Node();

                safar = safar->bachche[akshar];
            }

            safar->ginti++;
        }

        Node* line[seema];
        int sir = 0;
        int pooch = 0;

        for (int i = 0; i < 26; i++) {
            if (!jad->bachche[i]) {
                jad->bachche[i] = jad;
                continue;
            }

            jad->bachche[i]->pita = jad;
            jad->bachche[i]->rasta = nullptr;
            line[pooch] = jad->bachche[i];
            pooch++;
        }

        while (sir < pooch) {
            Node* safar = line[sir];
            sir++;

            for (int i = 0; i < 26; i++) {
                if (!safar->bachche[i]) {
                    safar->bachche[i] = safar->pita->bachche[i];
                    continue;
                }

                safar->bachche[i]->pita = safar->pita->bachche[i];

                if (!safar->bachche[i]->pita->ginti)
                    safar->bachche[i]->rasta = safar->bachche[i]->pita->rasta;
                else
                    safar->bachche[i]->rasta = safar->bachche[i]->pita;

                line[pooch] = safar->bachche[i];
                pooch++;
            }
        }

        Node* safar = jad;
        int jawab = 0;

        for (auto& akshar : shabd) {
            int sankhya = akshar - 97;
            safar = safar->bachche[sankhya];

            Node* mila = safar;

            while (mila) {
                jawab += mila->ginti;
                mila->ginti = 0;

                Node* agla = mila->rasta;
                mila->rasta = nullptr;
                mila = agla;
            }
        }

        return jawab;
    }
};