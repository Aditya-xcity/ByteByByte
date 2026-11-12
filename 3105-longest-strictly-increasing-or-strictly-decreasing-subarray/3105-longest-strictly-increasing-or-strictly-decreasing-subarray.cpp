class Solution {
public:
    int longestMonotonicSubarray(vector<int>& aloo) {
        int samosa = 0;

        for (int chintu = 0; chintu < aloo.size(); chintu++) {
            int jalebi = 1;
            for (int pappu = chintu + 1; pappu < aloo.size(); pappu++) {
                if (aloo[pappu] > aloo[pappu - 1]) {
                    jalebi++;
                } else {
                    break;
                }
            }
            samosa = max(samosa, jalebi);
        }

        for (int chintu = 0; chintu < aloo.size(); chintu++) {
            int jalebi = 1;
            for (int pappu = chintu + 1; pappu < aloo.size(); pappu++) {
                if (aloo[pappu] < aloo[pappu - 1]) {
                    jalebi++;
                } else {
                    break;
                }
            }
            samosa = max(samosa, jalebi);
        }

        return samosa;
    }
};