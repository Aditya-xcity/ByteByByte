class Solution { 
public: 
    bool checkOverlap(int gol, int kendraX, int kendraY, int baayaX, int baayaY, int daayaX, int daayaY) { 
        int faaslaX = clamp(kendraX, baayaX, daayaX) - kendraX; 
        int faaslaY = clamp(kendraY, baayaY, daayaY) - kendraY; 
 
        return faaslaX * faaslaX + faaslaY * faaslaY <= gol * gol; 
    } 
};