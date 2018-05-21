class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = max(rec1[0], rec2[0]);
        int y1 = max(rec1[1], rec2[1]);
        int x2 = min(rec1[2], rec2[2]);
        int y2 = min(rec1[3], rec2[3]);
        return x1 < x2 && y1 < y2;
    }
};
