class Solution {
public:
    vector<int> busiestServers(int kitne, vector<int>& aana, vector<int>& kaam) {

        vector<int> jawab;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> line;
        set<int> khaali;

        for(int chakkar = 0; chakkar < kitne; chakkar++) {
            khaali.insert(chakkar);
        }

        vector<int> hisaab(kitne, 0);

        int kul = aana.size();
        int sabseZyada = 0;

        for(int chakkar = 0; chakkar < kul; chakkar++) {

            while(!line.empty() && aana[chakkar] >= line.top().first) {
                khaali.insert(line.top().second);
                line.pop();
            }

            if(khaali.size() == 0) continue;

            int baari = chakkar % kitne;
            auto dhundo = khaali.lower_bound(baari);

            int mila = -1;

            if(dhundo == khaali.end()) {
                mila = *khaali.begin();
            } else {
                mila = *dhundo;
            }

            khaali.erase(mila);

            line.push({aana[chakkar] + kaam[chakkar], mila});
            hisaab[mila]++;

            sabseZyada = max(sabseZyada, hisaab[mila]);
        }

        for(int chakkar = 0; chakkar < kitne; chakkar++) {

            if(hisaab[chakkar] == sabseZyada) {
                jawab.push_back(chakkar);
            }
        }

        return jawab;
    }
};