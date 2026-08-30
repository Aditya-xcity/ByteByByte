class Solution { 
public: 
    int minimumDeletions(vector<int>& nums) { 
        int ginti = nums.size(); 
        int chhota = 0; 
        int bada = 0; 
         
        for (int i = 1; i < ginti; i++) { 
            if (nums[i] < nums[chhota]) 
                chhota = i; 
                 
            if (nums[i] > nums[bada]) 
                bada = i; 
        } 
         
        if (chhota < bada) 
            swap(chhota, bada); 
             
        int jawab = ginti; 
         
        for (int i = 0; i <= ginti; i++) { 
            int bacha = 0; 
             
            if (bada >= i) 
                bacha = ginti - bada; 
            else if (chhota >= i) 
                bacha = ginti - chhota; 
                 
            jawab = min(jawab, i + bacha); 
        } 
         
        return jawab; 
    } 
};