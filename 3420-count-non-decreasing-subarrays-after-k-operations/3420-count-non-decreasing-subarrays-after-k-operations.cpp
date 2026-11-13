class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int kitne = nums.size();
        long long jawab = 0;
        long long kharcha = 0;

        priority_queue<pair<int, int>> dabba;
        vector<vector<int>> jhund(kitne);
        vector<int> agla(kitne, kitne);
        stack<int> dher;

        for (int shuru = 0, aage = 0; aage < kitne; aage++) {
            while (!dher.empty() && nums[aage] >= nums[dher.top()]) {
                agla[dher.top()] = aage;
                dher.pop();
            }

            if (!dher.empty()) {
                jhund[dher.top()].push_back(aage);
            }

            dher.push(aage);

            dabba.emplace(nums[aage], aage);

            kharcha += max(0, dabba.top().first - nums[aage]);

            while (kharcha > k) {
                for (int banda : jhund[shuru]) {
                    kharcha -=
                        (long long)(nums[shuru] - nums[banda]) *
                        (min(agla[banda], aage + 1) - banda);
                }
                shuru++;
            }

            while (!dabba.empty() && dabba.top().second < shuru) {
                dabba.pop();
            }

            jawab += aage - shuru + 1;
        }

        return jawab;
    }
};