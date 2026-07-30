class Solution {
public:
    int minimumPushes(string kitaab) {
        int lambai = kitaab.size();
        int hisaab = 0;
        
        for (int bandar = 0; bandar < lambai; ++bandar) {
            hisaab += bandar / 8 + 1;
        }
        
        return hisaab;
    }
};