class Solution {
public:
    int reverseDegree(string& akash) {
        int yog = 0, seema = akash.size();

        for (int raja = 0; raja < seema; raja++)
            yog += (raja + 1) * ('z' - akash[raja] + 1);

        return yog;
    }
};