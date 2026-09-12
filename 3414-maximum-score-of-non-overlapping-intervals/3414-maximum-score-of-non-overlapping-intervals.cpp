class Solution { 
public: 
    vector<int> maximumWeight(vector<vector<int>>& intervals) { 
        int sankhya = intervals.size(); 
        vector<tuple<int, int, int, int>> dabba; 

        for (int ram = 0; ram < sankhya; ram++) { 
            int baaya = intervals[ram][0], 
                daaya = intervals[ram][1], 
                bhaar = intervals[ram][2]; 

            dabba.emplace_back(baaya, daaya, bhaar, ram); 
        } 

        // Sort by right endpoint. 
        sort(dabba.begin(), dabba.end(), 
             [](auto&& pehla, auto&& doosra) { 
                 return get<1>(pehla) < get<1>(doosra); 
             }); 

        vector<vector<long long>> ginti(
            sankhya + 1, vector<long long>(5)
        ); 

        vector<vector<vector<int>>> suchi(
            sankhya + 1, vector<vector<int>>(5)
        ); 

        for (int ram = 0; ram < sankhya; ram++) { 
            auto [baaya, daaya, bhaar, pehchaan] = dabba[ram]; 

            // Use binary search to find intervals whose right endpoints are 
            // smaller than l. 
            int padosi = lower_bound(
                dabba.begin(), 
                dabba.begin() + ram, 
                baaya, 
                [](const tuple<int, int, int, int>& vastu, int maan) { 
                    return get<1>(vastu) < maan; 
                }
            ) - dabba.begin(); 

            for (int chaal = 1; chaal < 5; chaal++) { 
                long long purana = ginti[ram][chaal]; 
                long long naya = ginti[padosi][chaal - 1] + bhaar; 

                if (purana > naya) { 
                    ginti[ram + 1][chaal] = ginti[ram][chaal]; 
                    suchi[ram + 1][chaal] = suchi[ram][chaal]; 
                    continue; 
                } 

                vector<int> nayiSuchi = suchi[padosi][chaal - 1]; 
                nayiSuchi.push_back(pehchaan); 
                sort(nayiSuchi.begin(), nayiSuchi.end()); 

                if (purana == naya && suchi[ram][chaal] < nayiSuchi) { 
                    nayiSuchi = suchi[ram][chaal]; 
                } 

                ginti[ram + 1][chaal] = naya; 
                suchi[ram + 1][chaal] = nayiSuchi; 
            } 
        } 

        return suchi[sankhya][4]; 
    } 
};