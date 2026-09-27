class Solution { 
public: 
    string reverseParentheses(auto& naam) { 
        int lambai = naam.size(); 
        vector<int> jod(lambai), dabba; 
 
        for (int i = 0; i < lambai; i++) { 
            if (naam[i] == '(') 
                dabba.push_back(i); 
            else if (naam[i] == ')') { 
                jod[i] = dabba.back(); 
                jod[jod[i]] = i; 
                dabba.pop_back(); 
            } 
        } 
 
        string jawab; 
        for (int i = 0, disha = 1; i < lambai; i += disha) { 
            if (naam[i] >= 'a') 
                jawab += naam[i]; 
            else { 
                i = jod[i]; 
                disha = -disha; 
            } 
        } 
 
        return jawab; 
    } 
};