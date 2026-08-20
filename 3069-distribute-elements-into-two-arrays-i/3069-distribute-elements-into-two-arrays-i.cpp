class Solution { 
public: 
    vector<int> resultArray(vector<int>& sankhya) { 
        vector<int> samuha[2]={{sankhya[0]}, {sankhya[1]}}; 
        const int aakar=sankhya.size(); 
        
        for(int ginti=2; ginti<aakar; ginti++){ 
            samuha[samuha[0].back()<=samuha[1].back()].push_back(sankhya[ginti]); 
        } 
        
        samuha[0].insert(samuha[0].end(), samuha[1].begin(), samuha[1].end()); 
        return samuha[0]; 
    } 
}; 
 
auto aarambh = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 'c'; 
}();