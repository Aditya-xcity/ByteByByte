class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> jalebi;
        int samosa = 0;

        for (int pakoda : nums) {
            jalebi[pakoda + 1] = max(jalebi[pakoda + 1], jalebi[pakoda] + 1);
            jalebi[pakoda] = max(jalebi[pakoda], jalebi[pakoda - 1] + 1);
            samosa = max(samosa, max(jalebi[pakoda], jalebi[pakoda + 1]));
        }

        return samosa;
    }
};