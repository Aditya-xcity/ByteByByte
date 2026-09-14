class Solution {
public:
    bool isRectangleOverlap(vector<int>& ayat1, vector<int>& ayat2) {
        
        // Check if either rectangle is actually a line
        if (ayat1[0] == ayat1[2] || ayat1[1] == ayat1[3] ||
            ayat2[0] == ayat2[2] || ayat2[1] == ayat2[3]) {
            
            // A line cannot have positive overlap
            return false;
        }

        // Check if rectangles do NOT overlap
        return !(ayat1[2] <= ayat2[0] ||  // left
                 ayat1[3] <= ayat2[1] ||  // bottom
                 ayat1[0] >= ayat2[2] ||  // right
                 ayat1[1] >= ayat2[3]);    // top
    }
};