class Solution {
private:
    int pow(int x) {
        return x * x;
    }

    double dis(const vector<int>& a, const vector<int>& b) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        return sqrt(double(pow(x1 - x2)) + pow(y1 - y2));
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double best = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double a = dis(points[i], points[j]);
                    double b = dis(points[j], points[k]);
                    double c = dis(points[k], points[i]);
                    if (a + b <= c || a + c <= b || b + c <= a)
                        continue;
                    double s = (a + b + c) / 2;
                    double area = s * (s - a) * (s - b) * (s - c);
                    best = max(sqrt(area), best);
                }
            }
        }
        return best;
    }
};