class Solution {
public:
    string smallestPalindrome(string laddu) {
        int lambai = laddu.length();
        int aadha = lambai / 2;

        sort(laddu.begin(), laddu.begin() + aadha);

        for (int jalebi = 0; jalebi < aadha; ++jalebi) {
            laddu[lambai - 1 - jalebi] = laddu[jalebi];
        }

        return laddu;
    }
};