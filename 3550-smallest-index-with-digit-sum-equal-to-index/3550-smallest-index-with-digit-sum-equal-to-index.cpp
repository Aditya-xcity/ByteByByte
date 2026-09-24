class Solution { 
public: 
    int smallestIndex(vector<int>& sankhya) { 
        const int seema = min(28, int(sankhya.size())); 
        
        for(int i = 0; i < seema; i++) { 
            int ank = sankhya[i], yog = 0; 
            
            for(; ank > 0; ank /= 10) { 
                yog += ank % 10; 
            } 
            
            if(yog == i) return i; 
        } 
        
        return -1; 
    } 
};