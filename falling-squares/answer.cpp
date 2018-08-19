class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size(), h = positions[0].second;
        vector<int> ans = {h};
        vector<int> heights = {h};
        for (int i = 1; i < n; i++) {
            int a1 = positions[i].first;
            int a2 = a1 + positions[i].second;
            h = 0;
            for (int j = 0; j < i; j++) {
                int b1 = positions[j].first;
                int b2 = b1 + positions[j].second;
                if (max(a1, b1) < min(a2, b2))
                    h = max(h, heights[j]);
            }
            h += positions[i].second;
            heights.push_back(h);
            ans.push_back(max(ans.back(), h));
        }
        return ans;
    }
};
