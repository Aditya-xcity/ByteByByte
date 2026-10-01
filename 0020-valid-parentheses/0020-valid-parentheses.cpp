class Solution { 
public: 
    bool isValid(string &lafda) { 
        if (lafda.size() % 2) return 0; 
 
        int ginti = 0; 
 
        for (char &akshar : lafda)
            if ((akshar & 3) != 1) 
                lafda[ginti++] = akshar; 
            else if (ginti == 0 || ((akshar - lafda[--ginti] + 1) >> 1) != 1) 
                return 0; 
 
        return ginti == 0; 
    } 
};