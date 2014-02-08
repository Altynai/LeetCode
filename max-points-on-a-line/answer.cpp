#include <algorithm>
#include <vector>
using namespace std;

class PointSlopeComparator {
private:
    const Point &base;

public:
    PointSlopeComparator(const Point &point): base(point) {}
    bool operator() (const Point &lh, const Point &rh) {
        int x1 = lh.x - base.x, y1 = lh.y - base.y;
        int x2 = rh.x - base.x, y2 = rh.y - base.y;
        return y1 * x2 < y2 * x1;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxCount = 0;
        for (int i = 0; i < points.size(); i++) {
            vector<Point> temp_points;
            temp_points.push_back(points[i]);
            int same_count = 0; // same point
            // 1. vertical
            int vertical_count = 0;
            for (int j = 0; j < points.size(); j++) {
                if(i == j)
                    continue;
                if (points[i].x == points[j].x)
                    points[i].y == points[j].y ? same_count++ : vertical_count++;
                else
                    temp_points.push_back(points[j]);
            }
            maxCount = std::max(maxCount, vertical_count + 1 + same_count);
            // 2. normal line
            sortPointsBySlope(temp_points); // O(nlogn)
            maxCount = std::max(maxCount, countMaxPoints(temp_points) + same_count);
        } // O(n^2logn)
        return maxCount;
    }

private:
    int countMaxPoints(vector<Point> &points) {
        if (points.size() <= 2)
            return points.size();
        int maxCount = 2, currCount = 2;
        Point &base = points[0];
        for (int i = 2; i < points.size(); i++) {
            if (pointsLieStraight(base, points[i-1], points[i])) {
                currCount++;
                maxCount = std::max(maxCount, currCount);
            } else {
                currCount = 2;
            }
        }
        return maxCount;
    }

    bool pointsLieStraight(const Point &base, const Point &lh, const Point &rh) {
        int x1 = lh.x - base.x, y1 = lh.y - base.y;
        int x2 = rh.x - base.x, y2 = rh.y - base.y;
        return x1 * y2 == y1 * x2;
    }

    void sortPointsBySlope(vector<Point> &points) {
        if (points.size() <= 2)
            return;
        std::sort(points.begin() + 1, points.end(), PointSlopeComparator(points[0]));
    }
};