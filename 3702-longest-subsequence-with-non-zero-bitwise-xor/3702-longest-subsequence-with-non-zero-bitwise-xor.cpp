class Solution { 
public: 
    int longestSubsequence(vector<int>& nums) { 
        int gagan = nums.size(); 
        int totalXor = 0; 
        bool sabShunya = true; 
 
        for (int x : nums) { 
            totalXor ^= x; 
            if (x > 0) { 
                sabShunya = false; 
            } 
        } 
 
        if (totalXor > 0) { 
            return gagan; 
        } 
 
        return sabShunya ? 0 : gagan - 1; 
    } 
};