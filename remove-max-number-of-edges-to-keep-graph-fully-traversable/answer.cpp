struct DSU {
    #define maxm 100005
    int n;
    int p[maxm];

    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        int r = x;
        while (p[r] != r)
            r = p[r];
        int i = x;
        while (p[i] != r) {
            int j = p[i];
            p[i] = r;
            i = j;
        }
        return r;
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);
        p[y] = x;
    }
} dsu;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        int m = e.size();
        sort(e.begin(), e.end(), [](vector<int>& lh, vector<int>& rh) {
            return lh[0] > rh[0];
        });

        auto cal = [&](int type) -> vector<int> {
            dsu.init(n + 1);

            int i = 0, common = 0;
            for (i = 0; i < m && e[i][0] == 3; i++) {
                if (dsu.find(e[i][1]) != dsu.find(e[i][2])) {
                    common++;
                    dsu.join(e[i][1], e[i][2]);
                }
            }
            for (; i < m && e[i][0] != type; i++);
            
            int need = 0;
            for (; i < m && e[i][0] == type; i++) {
                if (dsu.find(e[i][1]) != dsu.find(e[i][2])) {
                    need++;
                    dsu.join(e[i][1], e[i][2]);
                }
            }
            
            int r = dsu.find(1);
            for (int j = 2; j <= n; j++) {
                if (dsu.find(j) != r) {
                    return {-1, - 1};
                }
            }
            return {common, need};
        };
        
        vector<int> ans1 = cal(1);
        if (ans1[0] == -1) return -1;
        vector<int> ans2 = cal(2);
        if (ans2[0] == -1) return -1;
        return m - (ans1[0] + ans1[1] + ans2[1]);
    }
};
