class Solution {
public:
    int maxSubarrayLength(vector<int>& sankhya, int seema) {
        int uttar = 0, shuru = -1;
        unordered_map<int, int> ginti;

        for (int ant = 0; ant < sankhya.size(); ant++) {
            ginti[sankhya[ant]]++;

            while (ginti[sankhya[ant]] > seema) {
                shuru++;
                ginti[sankhya[shuru]]--;
            }

            uttar = max(uttar, ant - shuru);
        }

        return uttar;
    }
};