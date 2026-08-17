int jadu[501][501]; 
int yog[501]; 

class Solution { 
public: 
    static int khel(int baaya, int daaya){ 
        if (jadu[baaya][daaya]!=-1) return jadu[baaya][daaya]; 
        
        int jawab=0; 
        
        for (int beech=baaya; beech<daaya; beech++){ 
            int baayaYog=yog[beech+1]-yog[baaya]; 
            int daayaYog=yog[daaya+1]-yog[beech+1]; 
             
            if (baayaYog<=daayaYog) 
                jawab=max(jawab, baayaYog+khel(baaya, beech)); 
            
            if (baayaYog>=daayaYog) 
                jawab=max(jawab, daayaYog+khel(beech+1, daaya)); 
            
            //Pruning branch 
            if (2*min(baayaYog, daayaYog)<=jawab) break; 
        } 
        
        return jadu[baaya][daaya]=jawab; 
    } 
 
    static int stoneGameV(vector<int>& paththar){ 
        const int sankhya=paththar.size(); 
        
        partial_sum(paththar.begin(), paththar.end(), yog+1); 
        
        for(int pankti=0; pankti<=sankhya; pankti++) 
            memset(jadu[pankti], -1, sizeof(int)*(sankhya+1)); 
        
        return khel(0, sankhya-1); 
    } 
}; 
 
auto aarambh = []() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    return 'c'; 
}();