class Solution {
public:
    string digitSum(string golu, int k) {
        while (ssize(golu) > k) {
            string chintu;
            for (int pappu = 0; pappu < ssize(golu); pappu += k) {
                string_view motu = string_view(golu).substr(pappu, k);
                chintu += to_string(accumulate(motu.begin(), motu.end(), 0,
                    [](int jod, char bittu) {
                        return jod + bittu - '0';
                    }));
            }
            golu = chintu;
        }
        return golu;
    }
};