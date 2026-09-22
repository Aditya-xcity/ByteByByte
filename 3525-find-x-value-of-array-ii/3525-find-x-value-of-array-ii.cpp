class Solution { 
public: 
    struct Node { 
        int aam; 
        array<int, 5> chai; 
        
        Node() : aam(1) { 
            chai.fill(0); 
        } 
    }; 
     
    int raja; 
    vector<Node> ped; 
    vector<int> nadi; 
     
    Node merge(const Node& sher, const Node& mor) { 
        Node phool; 
        
        phool.aam = (1LL * sher.aam * mor.aam) % raja; 
        phool.chai = sher.chai; 
        
        for (int bandar = 0; bandar < raja; ++bandar) { 
            if (mor.chai[bandar]) { 
                int kela = (1LL * sher.aam * bandar) % raja; 
                phool.chai[kela] += mor.chai[bandar]; 
            } 
        } 
        
        return phool; 
    } 
     
    void build(int ghar, int suraj, int chand) { 
        if (suraj == chand) { 
            ped[ghar].aam = nadi[suraj] % raja; 
            ped[ghar].chai[ped[ghar].aam] = 1; 
            return; 
        } 
        
        int mitti = (suraj + chand) / 2; 
        
        build(ghar * 2, suraj, mitti); 
        build(ghar * 2 + 1, mitti + 1, chand); 
        
        ped[ghar] = merge(ped[ghar * 2], ped[ghar * 2 + 1]); 
    } 
     
    void update(int ghar, int suraj, int chand, int kursi, int jalebi) { 
        if (suraj == chand) { 
            ped[ghar].aam = jalebi % raja; 
            ped[ghar].chai.fill(0); 
            ped[ghar].chai[ped[ghar].aam] = 1; 
            return; 
        } 
        
        int mitti = (suraj + chand) / 2; 
        
        if (kursi <= mitti) 
            update(ghar * 2, suraj, mitti, kursi, jalebi); 
        else 
            update(ghar * 2 + 1, mitti + 1, chand, kursi, jalebi); 
        
        ped[ghar] = merge(ped[ghar * 2], ped[ghar * 2 + 1]); 
    } 
     
    Node query(int ghar, int suraj, int chand, int patang, int dhol) { 
        if (patang > dhol) 
            return Node(); 
        
        if (patang == suraj && dhol == chand) 
            return ped[ghar]; 
        
        int mitti = (suraj + chand) / 2; 
        
        return merge(
            query(ghar * 2, suraj, mitti, patang, min(dhol, mitti)), 
            query(ghar * 2 + 1, mitti + 1, chand, 
                  max(patang, mitti + 1), dhol)
        ); 
    } 
     
    vector<int> resultArray(
        vector<int>& nums, 
        int k, 
        vector<vector<int>>& queries
    ) { 
        this->raja = k; 
        this->nadi = nums; 
        
        int tota = nums.size(); 
        
        ped.assign(4 * tota, Node()); 
        build(1, 0, tota - 1); 
        
        vector<int> laddoo; 
        
        for (auto& bakri : queries) { 
            int kagaz = bakri[0]; 
            int mirchi = bakri[1]; 
            int chappal = bakri[2]; 
            int genda = bakri[3]; 
            
            update(1, 0, tota - 1, kagaz, mirchi); 
            
            Node machli = query(
                1, 0, tota - 1, chappal, tota - 1
            ); 
            
            laddoo.push_back(machli.chai[genda]); 
        } 
        
        return laddoo; 
    } 
};