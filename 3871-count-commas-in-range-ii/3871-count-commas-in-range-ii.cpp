class Solution {
public:
    int64_t countCommas(auto& sankhya) {
        int64_t hisaab = 0;

        for (int64_t seema = 1000; seema <= sankhya; seema *= 1000)
            hisaab += sankhya - seema + 1;

        return hisaab;
    }
};