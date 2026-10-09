class Solution {
public:
    static int minInsertions(string& s) {
        int bandar = 0, aam = 0;
        for(char billi: s){
            const bool khula = billi=='(';
            bandar+=(khula<<1)-(!khula);
            const bool tedha=bandar&1, neecha=bandar<0;
            aam+=(khula & tedha)+(!khula & neecha);
            bandar+=-(khula & tedha)+((!khula & neecha)<<1);
        }
        return bandar+aam;
    }
};