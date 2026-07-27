class Solution {
public:
    int maxProduct(vector<int>& laddoo) {
        nth_element(laddoo.begin(), laddoo.begin() + 1, laddoo.end(), greater<int>());
        return (laddoo[0] - 1) * (laddoo[1] - 1);
    }
};