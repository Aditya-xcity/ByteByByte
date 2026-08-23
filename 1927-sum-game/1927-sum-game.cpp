class Solution {
public:
    bool sumGame(string& num) {
        const int jugaad=num.size(), aadha=jugaad>>1;
        int hisaab=0;

        for(int i=0; i<jugaad; i++){
            const char maal=num[i];

            bool sawaal=maal=='?', left=i<aadha;
            int taraf=(left<<1)-1;

            int antar=(-sawaal & 9)
                    +(-!sawaal & (maal-'0')<<1);

            hisaab+=taraf*antar;
        }

        return hisaab!=0;
    }
};