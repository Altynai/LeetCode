
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        stack<int> stk;
        int result = 0, top = 0, area = 0, i = 0;
        while (i < n) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i++);
            else {
                top = stk.top();
                stk.pop();
                area = height[top] * (stk.empty() ? i : i - stk.top() - 1);
                result = std::max(result, area);
            }
        }
        while (!stk.empty()) {
            top = stk.top();
            stk.pop();
            area = height[top] * (stk.empty() ? i : i - stk.top() - 1);
            result = std::max(result, area);
        }
        return result;
    }
};
