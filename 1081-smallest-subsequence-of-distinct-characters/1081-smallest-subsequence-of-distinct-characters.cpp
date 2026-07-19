class Solution {
public:
    string smallestSubsequence(string shabd) {
        vector<int> nishan(26), ginti(26);

        for (char akshar : shabd) {
            ginti[akshar - 'a']++;
        }

        string pitara;

        for (char akshar : shabd) {
            if (!nishan[akshar - 'a']) {
                while (!pitara.empty() && pitara.back() > akshar) {
                    if (ginti[pitara.back() - 'a'] > 0) {
                        nishan[pitara.back() - 'a'] = 0;
                        pitara.pop_back();
                    } else {
                        break;
                    }
                }
                nishan[akshar - 'a'] = 1;
                pitara.push_back(akshar);
            }
            ginti[akshar - 'a']--;
        }

        return pitara;
    }
};