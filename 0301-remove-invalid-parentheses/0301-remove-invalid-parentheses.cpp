class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> jawab;
        forward(s, jawab, 0, 0);

        return jawab;
    }

private:
    void forward(string shabd, auto& jawab, int aage, int pichla) {
        int santulan = 0;

        for (int i = aage; i < shabd.length(); i++) {
            santulan += (shabd[i] == '(') - (shabd[i] == ')');

            if (santulan >= 0) continue;

            for (int j = pichla; j <= i; j++)
                if (shabd[j] == ')' && (j == pichla || shabd[j - 1] != ')'))
                    forward(
                        shabd.substr(0, j) + shabd.substr(j + 1),
                        jawab,
                        i,
                        j
                    );

            return;
        }

        backward(shabd, jawab, shabd.length() - 1, shabd.length() - 1);
    }

    void backward(string shabd, auto& jawab, int ulta, int antim) {
        int santulan = 0;

        for (int i = ulta; i >= 0; i--) {
            santulan += (shabd[i] == ')') - (shabd[i] == '(');

            if (santulan >= 0) continue;

            for (int j = antim; j >= i; j--)
                if (shabd[j] == '(' &&
                    (j == antim || shabd[j + 1] != '('))
                    backward(
                        shabd.substr(0, j) + shabd.substr(j + 1),
                        jawab,
                        i - 1,
                        j - 1
                    );

            return;
        }

        jawab.push_back(shabd);
    }
};