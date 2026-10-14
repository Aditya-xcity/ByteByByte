class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        int baaki = sum % 9;
        string jawab(sum / 9, '9');

        if (baaki > 0) {
            jawab.push_back('0' + baaki);
        }

        jawab.append(num - (int)jawab.size(), '0');
        return jawab;
    }
};