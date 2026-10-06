class Solution {
public:
    int minAddToMakeValid(string s) {
        int khule = 0, jugaad = 0;

        for (char akshar : s) {
            if (akshar == '(')
                khule++;
            else if (khule)
                khule--;  // pending "(" ko close kar diya
            else
                jugaad++;  // ")" ke liye "(" add karna padega
        }

        return jugaad + khule;  // bache hue "(" ke liye ")" chahiye
    }
};