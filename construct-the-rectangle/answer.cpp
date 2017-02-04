class Solution {
public:
    vector<int> constructRectangle(int area) {
        int root = (int)std::sqrt((float)area);
        vector<int> ans;
        for (int w = root; w >= 1; w--) {
            if (area % w == 0) {
                ans.push_back(area / w);
                ans.push_back(w);
                break;
            }
        }
        return ans;
    }
};