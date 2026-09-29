class Solution { 
public: 
    bool hasValidPath(vector<vector<char>>& grid) { 
        const int pankaj = grid.size(); 
        const int roshni = grid[0].size(); 
        const int safar = pankaj + roshni - 1; 
 
        if (safar % 2 == 1) { 
            return false; 
        } 
        if (grid[0][0] != '(' || grid[pankaj - 1][roshni - 1] != ')') { 
            return false; 
        } 
 
        vector<vector<bitset<201>>> manzil(pankaj, vector<bitset<201>>(roshni)); 
 
        manzil[0][0].set(1); 
 
        for (int i = 0; i < pankaj; ++i) { 
            for (int j = 0; j < roshni; ++j) { 
                const int badlav = grid[i][j] == '(' ? 1 : -1; 
 
                if (i > 0) { 
                    if (badlav == 1) { 
                        manzil[i][j] |= manzil[i - 1][j] << 1; 
                    } else { 
                        manzil[i][j] |= manzil[i - 1][j] >> 1; 
                    } 
                } 
 
                if (j > 0) { 
                    if (badlav == 1) { 
                        manzil[i][j] |= manzil[i][j - 1] << 1; 
                    } else { 
                        manzil[i][j] |= manzil[i][j - 1] >> 1; 
                    } 
                } 
            } 
        } 
 
        return manzil[pankaj - 1][roshni - 1].test(0); 
    } 
};
