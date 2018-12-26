#define N 1
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

const i64 MOD = 40000 + 7;

struct _pair_hash {
    size_t operator()(const PII& p) const {
        return p.first * MOD + p.second;
    }
};

class Solution {
private:
    double get_area(const PII& v1, const PII& v2) {
        double square1 = v1.first * v1.first + v1.second * v1.second;
        double square2 = v2.first * v2.first + v2.second * v2.second;
        return sqrt(square1) * sqrt(square2);
    }

public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        std::unordered_set<PII, _pair_hash> seen;
        FOR(i, 0, n) seen.insert(MP(points[i][0], points[i][1]));

        double ans = 0;
        FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n) {
            if (i == j || j == k || i == k)
                continue;
            vector<int>& p0 = points[i];
            vector<int>& p1 = points[j];
            vector<int>& p2 = points[k];
            PII v1 = MP(p1[0] - p0[0], p1[1] - p0[1]);
            PII v2 = MP(p2[0] - p0[0], p2[1] - p0[1]);

            int dp = v1.first * v2.first + v1.second * v2.second;
            if (dp != 0)
                continue;
            PII target = MP(p0[0] + v1.first + v2.first, p0[1] + v1.second + v2.second);
            if (seen.find(target) == seen.end())
                continue;

            double area = get_area(v1, v2);
            if (ans == 0 || area < ans)
                ans = area;
        }
        return ans;
    }
};
