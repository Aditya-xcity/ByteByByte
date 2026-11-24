class Solution {
public:
    int maxLength(vector<int>& dabba) {
        int mithai = 2, bandar = 0, laddoo = 1;

        for (int tota = 0; tota < ssize(dabba); ++tota) {
            int aloo = dabba[tota];

            while (gcd(laddoo, aloo) > 1)
                laddoo /= dabba[bandar++];

            laddoo *= aloo;
            mithai = max(mithai, tota - bandar + 1);
        }

        return mithai;
    }
};