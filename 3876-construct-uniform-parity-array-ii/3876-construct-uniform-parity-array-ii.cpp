class Solution {
public:
    bool uniformArray(vector<int>& sankhya) {
        int sabseChhota = sankhya[0];
        bool visham = 0;

        for (auto& tattva : sankhya) {
            sabseChhota = min(sabseChhota, tattva);
            visham |= tattva & 1;
        }

        return (sabseChhota & 1) == visham;
    }
};