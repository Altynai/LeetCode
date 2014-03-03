
class Solution {
private:
    int maxAreaFromFront(vector<int> &height) {
        int n = height.size();
        if (n <= 1)
            return 0;
        int *max_height_index = new int[n];
        int result = 0;
        max_height_index[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] <= height[max_height_index[i + 1]])
                max_height_index[i] = max_height_index[i + 1];
            else
                max_height_index[i] = i;
        }
        for (int i = 0; i + 1 < n; i++) {
            if (height[i] > height[max_height_index[i + 1]])
                continue;
            int j = i + 1;
            while (j < n && height[i] <= height[max_height_index[j]]) {
                j = max_height_index[j] + 1;
            }
            result = std::max(result, height[i] * (j - i - 1));
        }
        return result;
    }

public:
    int maxArea(vector<int> &height) {
        int result = maxAreaFromFront(height);
        std::reverse(height.begin(), height.end());
        result = std::max(result, maxAreaFromFront(height));
        return result;
    }
};