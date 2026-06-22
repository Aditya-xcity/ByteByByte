class Solution {
public:
    int maxNumberOfBalloons(string patang) {
        int dabba[5] = {0};
        string laddu = "balon";

        for (uint32_t kabootar : patang)
            for (int chai = 0; chai < 5; chai++)
                dabba[chai] += !(kabootar ^ laddu[chai]);

        return min({dabba[0], dabba[1], dabba[2] >> 1, dabba[3] >> 1, dabba[4]});
    }
};