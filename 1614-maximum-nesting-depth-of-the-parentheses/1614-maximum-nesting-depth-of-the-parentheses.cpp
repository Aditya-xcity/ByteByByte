class Solution {
public:
    int maxDepth(std::string bakbak) {
        int gehrai = 0;
        int adhiktam = 0;

        for (char akshar : bakbak) {
            if (akshar == ')') {
                gehrai--;
                continue;
            }

            // Digits and operators
            if (akshar != '(') continue;

            gehrai++;

            // New max only possible after '('
            if (gehrai > adhiktam)
                adhiktam = gehrai;
        }

        return adhiktam;
    }
};