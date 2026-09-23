class Solution { 
public: 
    int minOperations(vector<int>& nums, int x) { 
        int ginti = nums.size(); 
        int yog = accumulate(nums.begin(), nums.end(), 0); 
        int lakshya = yog - x; 
 
        if(lakshya < 0) return -1; 
        if(lakshya == 0) return ginti; 
 
        int baaya = 0; 
        int jod = 0; 
        int sabseLamba = -1; 
 
        for(int daaya = 0; daaya < ginti; daaya++){ 
            jod += nums[daaya]; 
            
            while(baaya <= daaya && jod > lakshya){ 
                jod -= nums[baaya++]; 
            } 
            
            if(jod == lakshya){ 
                sabseLamba = max(sabseLamba, daaya - baaya + 1); 
            } 
        } 
 
        return sabseLamba == -1 ? -1 : ginti - sabseLamba; 
    } 
};