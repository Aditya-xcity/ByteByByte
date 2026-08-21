class Solution { 
public: 
    using ll = long long; 

    long long findKthSmallest(vector<int>& sikke, int k) { 
        ranges::sort(sikke); 
        vector<int> chuney; 
 
        for (auto& sikka : sikke) 
            if (ranges::none_of(chuney, [&](int cheez) { return !(sikka % cheez); })) 
                chuney.push_back(sikka); 
 
        int ginati = chuney.size(); 
 
        auto checkKaro = [&](ll beech) { 
            ll kul = 0; 
            for (int kitne = 1; kitne <= ginati; kitne++) { 
                int group = (1 << kitne) - 1; 
 
                while (group < 1 << ginati) { 
                    ll value = 1; 
                    for (int index = 0; index < ginati; index++) 
                        if ((group >> index) & 1) 
                            value = lcm(value, chuney[index]); 
 
                    kul += (beech / value) * (((kitne & 1) << 1) - 1); 
 
                    int chhota = group & -group; 
                    int agla = group + chhota; 
                    group = (((agla ^ group) >> 2) / chhota) | agla; 
                } 
            } 
            return kul >= k; 
        }; 
 
        ll neeche = k, upar = 1ll * chuney[0] * k; 
        return *ranges::lower_bound(views::iota(neeche, upar + 1), true, {}, 
                                    [&](ll beech) { return checkKaro(beech); }); 
    } 
};