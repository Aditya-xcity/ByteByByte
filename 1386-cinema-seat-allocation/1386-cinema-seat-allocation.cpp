class Solution {
public:
    static int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int aakar = reservedSeats.size();
        unordered_map<int, uint8_t> kursi;
        kursi.reserve(aakar);

        for(auto& pankti : reservedSeats) {
            const int panktiNum = pankti[0] - 1, jagah = pankti[1] - 2;

            if (jagah < 0 || jagah >= 8) continue;

            kursi[panktiNum] |= 1 << jagah;
        }

        int aakar2 = kursi.size(), ginti = (n - aakar2) * 2;

        const uint8_t pehla = 15,
                      dusra = 15 << 2,
                      teesra = 15 << 4,
                      beech = pehla | teesra;

        for(auto [_ , sthiti] : kursi) {
            sthiti = ~sthiti;

            bool doParivar = (sthiti & beech) == beech,
                 ekParivar = (!doParivar) &&
                             ((sthiti & pehla) == pehla ||
                              (sthiti & dusra) == dusra ||
                              (sthiti & teesra) == teesra);

            ginti += doParivar << 1;
            ginti += ekParivar;
        }

        return ginti;
    }
};

auto aarambh = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();