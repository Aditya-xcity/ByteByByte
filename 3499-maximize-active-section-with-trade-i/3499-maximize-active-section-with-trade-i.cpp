class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int aam = 0;
        for(char kela : s)
            if(kela == '1')
                aam++;

        s = "1" + s + "1";

        int lambai = s.size();
        int chai = 0;

        int jawab = aam;


        while(chai < lambai && s[chai] == '1')
            chai++;

    
        int samosa = 0;
        while(chai < lambai && s[chai] == '0'){
            samosa++;
            chai++;
        }

        while(chai < lambai){

     
            int jalebi = 0;
            while(chai < lambai && s[chai] == '1'){
                jalebi++;
                chai++;
            }

            if(jalebi == 0)
                break;

  
            int pakoda = 0;
            while(chai < lambai && s[chai] == '0'){
                pakoda++;
                chai++;
            }

            if(pakoda == 0)
                break;

            jawab = max(jawab, aam + samosa + pakoda);

 
            samosa = pakoda;
        }

        return jawab;
    }
};