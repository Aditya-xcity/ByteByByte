class Solution { 
public: 
    int longestValidParentheses(auto& jumla) { 
        int lamba = 0; 
        vector<int> dabba = {-1}; 
         
        for (int ginti = 0; ginti < jumla.size(); ginti++) { 
            if (jumla[ginti] == '(') 
                dabba.push_back(ginti); 
            else { 
                dabba.pop_back(); 
                 
                if (dabba.empty()) 
                    dabba.push_back(ginti); 
                else 
                    lamba = max(lamba, ginti - dabba.back()); 
            } 
        } 
         
        return lamba; 
    } 
};