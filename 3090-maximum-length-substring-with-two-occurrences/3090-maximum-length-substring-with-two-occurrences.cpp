class Solution { 
public: 
    int maximumLengthSubstring(string s) { 
        int jawab = 0; 
        int ginti[26] = {0}; 
 
        for (int baaya = 0, daaya = 0; daaya < s.length(); daaya++) { 
            ginti[(s[daaya] & 31) - 1]++; 
 
            while (ginti[(s[daaya] & 31) - 1] > 2) 
                ginti[(s[baaya++] & 31) - 1]--; 
 
            jawab = max(jawab, daaya - baaya + 1); 
        } 
 
        return jawab; 
    } 
};